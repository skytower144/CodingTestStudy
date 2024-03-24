#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/* https://www.acmicpc.net/board/view/5434

dp[k][i][j] => k : 세계의 시드번호, i : 길이, j : 끝자리 숫자

98765 43210
-----------
00000 11010 => 1, 3, 4의 숫자를 가지고 있는 26번 세계
*/
int dp[1025][101][10] = {0, };

int UpdatedSeed(int seed, int addedNum) {
    seed |= (1 << addedNum);
    return seed;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    const int C = 1000000000;

    cin >> n;

    for (int j = 1; j <= 9; j++)
        dp[(int)pow(2, j)][1][j] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                for (int k = 0; k < 1024; k++) {
                    dp[UpdatedSeed(k, 0)][i][j] += dp[k][i - 1][1];
                    dp[UpdatedSeed(k, 0)][i][j] %= C;
                }
            }
            else if (j == 9) {
                for (int k = 0; k < 1024; k++) {
                    dp[UpdatedSeed(k, 9)][i][j] += dp[k][i - 1][8];
                    dp[UpdatedSeed(k, 9)][i][j] %= C;
                }
            }
            else {
                for (int k = 0; k < 1024; k++) {
                    dp[UpdatedSeed(k, j)][i][j] += (dp[k][i - 1][j - 1] + dp[k][i - 1][j + 1]) % C;
                    dp[UpdatedSeed(k, j)][i][j] %= C;
                }
            }
        }
    }
    int answer = 0;

    for (int j = 0; j <= 9; j++) {
        answer += dp[1023][n][j];
        answer %= C;
    }
    cout << answer;
    return 0;
}
