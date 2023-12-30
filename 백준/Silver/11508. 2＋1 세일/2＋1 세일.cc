#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int answer = 0;
    vector<int> yogurt(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> yogurt[i];
        answer += yogurt[i];
    }
    sort(yogurt.begin(), yogurt.end(), greater());

    for (int i = 2; i < n; i += 3) {
        answer -= yogurt[i];
    }
    cout << answer;
    return 0;
}