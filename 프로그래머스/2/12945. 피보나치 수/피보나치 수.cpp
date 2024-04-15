#include <string>
#include <vector>
#define C 1234567

using namespace std;

int solution(int n) {
    int dp[100000];
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % C;
    
    return dp[n];
}