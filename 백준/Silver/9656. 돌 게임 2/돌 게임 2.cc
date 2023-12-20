#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int dp[1001] = {0, };
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    
    for (int i = 4; i <= n; i++)
        dp[i] = min(dp[i - 1], dp[i - 3]) + 1;
    
    string answer = dp[n] % 2 ? "CY" : "SK";
    cout << answer;
    return 0;
}