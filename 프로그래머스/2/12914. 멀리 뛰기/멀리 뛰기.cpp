#include <string>
#include <vector>
#define C 1234567

using namespace std;

long long solution(int n) {
    long long dp[2001];
    dp[1] = 1, dp[2] = 2;
    
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % C;
    
    return dp[n];
}