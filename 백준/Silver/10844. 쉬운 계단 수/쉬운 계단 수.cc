#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int dp[101][11] = {0,};

    for (int j = 1; j <= 9; j++)
        dp[1][j] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }
    int answer = 0;
    for (int j = 0; j <= 9; j++)
        answer = (answer + dp[n][j]) % 1000000000;

    cout << answer;
    return 0;
}
/*
i : 길이
j : 끝나는 숫자

d[3][1]
3210

d[2][8]
789
989

d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1]

  0 1 2 3 4 5 6 7 8 9
1 0 1 1 1 1 1 1 1 1 1
2 1 1 2 2 2 2 2 2 2 1
3 1 3 3 4 4 4 4 4 3 2
4 3
5
*/