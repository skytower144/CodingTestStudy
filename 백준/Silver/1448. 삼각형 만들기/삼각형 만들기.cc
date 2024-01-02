#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> legs(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> legs[i];

    sort(legs.begin(), legs.end());
    int size = legs.size();
    int answer = -1;

    for (int i = size - 1; i >= 2; i--) {
        if (legs[i - 2] + legs[i - 1] > legs[i]) {
            answer = legs[i - 2] + legs[i - 1] + legs[i];
            break;
        }
    }
    cout << answer;
    return 0;
}