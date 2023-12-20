#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    bool dp[1001]; // 상근 기준
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;
    dp[5] = true;
    
    for (int i = 6; i <= n; i++) {
        if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
            dp[i] = true;
        else
            dp[i] = false;
    }
    string answer = dp[n] ? "SK" : "CY";
    cout << answer;
    return 0;
}