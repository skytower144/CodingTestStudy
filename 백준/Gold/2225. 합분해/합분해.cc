#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int dp[201][201] = {0,};
    
    for (int i = 0; i <= n; i++) 
        dp[1][i] = 1;
    
    for (int j = 1; j <= k; j++)
        dp[j][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[j][i] = (dp[j][i - 1] + dp[j - 1][i]) % 1000000000;
        }
    }
    cout << dp[k][n];
    return 0;
}