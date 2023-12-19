#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int answer = -1;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    vector<int> t(n + 2, 0);
    vector<int> p(n + 2, 0);
    vector<int> dp(n + 2, 0);

    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];
    
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        int nextPos = i + t[i];

        if (nextPos <= n + 1)
            dp[nextPos] = max(dp[nextPos], dp[i] + p[i]);
    }
    cout << max(dp[n], dp[n + 1]);
    return 0;
}