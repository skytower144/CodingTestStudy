#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> weight(n + 1, 0);
    vector<int> value(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];
    
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int w = 1; w <= k; w++) {
        for (int i = 1; i <= n; i++) {
            int includedValue;
            if (w - weight[i] < 0)
                includedValue = 0;
            else
                includedValue = dp[w - weight[i]][i - 1] + value[i];
            
            dp[w][i] = max(includedValue, dp[w][i - 1]);
        }
    }
    cout << dp[k][n];
    return 0;
}