#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> sticker(2, vector<int>(n, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++)
                cin >> sticker[i][j];
        }
        int maxValue = 0;
        vector<vector<int>> dp(2, vector<int>(n, 0));
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < 2; i++) {
                if (j < n - 1) {
                    dp[(i + 1) % 2][j + 1] = max(maxValue, dp[(i + 1) % 2][j + 1]);
                    dp[(i + 1) % 2][j + 1] = max(dp[(i + 1) % 2][j + 1], dp[i][j] + sticker[i][j]);
                }
            }
            maxValue = max(dp[0][min(n - 1, j + 1)], dp[1][min(n - 1, j + 1)]);

            // cout << "========================\n";
            // for (int i = 0; i < 2; i++) {
            //     for (int j = 0; j < n; j++)
            //         cout << dp[i][j] << " ";
            //     cout << endl;
            // }
        }
        cout << max(dp[0][n - 1] + sticker[0][n - 1], dp[1][n - 1] + sticker[1][n - 1]) << '\n';
    }
    return 0;
}