#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> pos(n, 0);
    for (int i = 0; i < n; i++) cin >> pos[i];
    sort(pos.begin(), pos.end());

    int answer;
    if (n % 2) answer = pos[n / 2];
    else answer = pos[n / 2 - 1];
    
    cout << answer;
    return 0;
}