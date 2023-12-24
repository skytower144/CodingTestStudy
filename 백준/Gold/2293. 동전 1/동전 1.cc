#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    vector<int> coins;
    vector<int> dp(k + 1, 0);

    int coinValue;
    for (int i = 0; i < n; i++) {
        cin >> coinValue;
        coins.push_back(coinValue);
    }
    sort(coins.begin(), coins.end());

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0 && j % coins[0] == 0)
                dp[j] = 1;
            
            else if (j >= coins[i])
                dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    cout << dp[k];
    return 0;
}
/*
1 / 2 / 5

[1]
1: 1
2: 11
3: 111
4: 1111
5: 11111
6: 111111
7: 1111111
8: 11111111
9: 111111111
10:1111111111

[1, 2]
1: 1
2: 11, 2
3: 111, 12
4: 1111, 112, 22
5: 11111, 1112, 122
6: 111111, 11112, 1122, 222
7: 1111111, 111112, 11122, 1222

[1, 2, 5]
1: 1
2: 11, 2
3: 111, 12
4: 1111, 112, 22
5: 11111, 1112, 122, 5
6: 111111, 11112, 1122, 222, 15
7: 1111111, 111112, 11122, 1222, 115, 25
*/