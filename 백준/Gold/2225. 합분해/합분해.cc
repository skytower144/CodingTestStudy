#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int dp[201][201] = {0,};

    for (int i = 1; i <= k; i++) {
        dp[0][i] = 1;
        dp[1][i] = i;
    }
    for (int j = 2; j <= n; j++) {
        for (int i = 1; i <= k; i++) {
            if (i == 1) {
                dp[j][i] = 1;
                continue;
            }
            for (int l = 0; l <= j; l++) {
                dp[j][i] += dp[j - l][i - 1] * dp[l][1];
                dp[j][i] %= 1000000000;
            }
        }
    }
    cout << dp[n][k];
    return 0;
}