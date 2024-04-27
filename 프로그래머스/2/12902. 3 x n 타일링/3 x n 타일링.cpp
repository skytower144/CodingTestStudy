#include <string>
#include <vector>
#include <iostream>
#define C 1000000007

using namespace std;

int solution(int n) {
    long long dp[5001] = {0, };
    
    dp[0] = 1;
    dp[2] = 3;
    
    for (int i = 4; i <= n; i += 2) {
        dp[i] += (dp[i - 2] * dp[2]) % C;
        
        for (int j = 4; i - j >= 0; j += 2)
            dp[i] += (dp[i - j] * 2) % C;
        
        dp[i] %= C;
    }
    return (int)dp[n];
}