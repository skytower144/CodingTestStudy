#include <iostream>

using namespace std;

int main() {
    int n;
    int dp[1001][10] = {0,};
    
    cin >> n;

    for (int j = 0; j <= 9; j++)
        dp[1][j] = 1;
    
    for (int i = 2; i <= n; i++)
        dp[i][0] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    int answer = 0;
    for (int j = 0; j <= 9; j++)
        answer = (answer + dp[n][j]) % 10007;
    
    cout << answer;
    return 0;
}
/*
i : 길이
j : 끝나는 숫자
dp[i][j] = dp[i][j - 1] + dp[i - 1][j]

  0 1 2 3 4 5
0 0 0 0 0 0 0
1 1 1 1 1 1 1
2 1 2 3 4 5 6 
3 1 3 6
4
5
5
*/