#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    vector<int> dp(11, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 10; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
