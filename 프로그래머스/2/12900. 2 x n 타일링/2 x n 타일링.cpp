#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    const int C = 1000000007;
    
    int dp[60000];
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % C;
    
    return dp[n];
}