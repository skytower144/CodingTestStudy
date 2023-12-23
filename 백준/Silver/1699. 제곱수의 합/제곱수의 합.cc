#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 2, 100000);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        int squareRoot = (int)sqrt(i);
        while (squareRoot) {
            dp[i] = min(dp[i], dp[i - pow(squareRoot, 2)] + 1);
            squareRoot--;
        }
    }
    cout << dp[n];

    return 0;
}
/*

1 : 1       (1)
2 : 1 1     (2)
3 : 1 1 1   (3)

4 : 2       (1)
5 : 2 1     (2)
6 : 2 1 1   (3)
7 : 2 1 1 1 (4)
8 : 2 2     (3)

9 : 3
10: 3 1
11: 3 1 1
12: 2 2 2
13: 3 2
14: 3 2 1
15: 3 2 1 1

16: 4
17: 4 1
18: 3 3

*/