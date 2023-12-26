#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> coins(n, 0);
    vector<int> dp(k + 1, 0);
    vector<int> count(k + 1, 0);

    for (int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            if (j == coins[i])
                count[j] = 1;
            else if (count[j - coins[i]] == 0)
                continue;
            else if (count[j] == 0)
                count[j] = count[j - coins[i]] + 1;
            else
                count[j] = min(count[j], count[j - coins[i]] + 1);
        }
        // for (int j = 1; j <= k; j++) cout << count[j] << " ";
        // cout << endl;
    }
    if (count[k] == 0) cout << -1;
    else cout << count[k];
    return 0;
}
/*

1)
1 : 1
2 : 11
3 : 111
4 : 1111
5 : 11111
6 : 111111
7 : 1111111

5)
1 : 1
2 : 11
3 : 111
5 : 11111 | 5
6 : 111111 | 15
7 : 1111111 | 115
9 : 111111111 | 11115
10 : 1111111111, 111115 | 55
11 : 155
12 : 1155
13 : 11155
14 : 111155
15 : 11111111111111..., 11111111115, 1111155 | 555

12)
1 : 1
2 : 11
3 : 111
12 : 111111111111, 12
13 : 1111111111111, 1-12
14 : 11111111111111, 11-12
15 : 기존, 111-12, 555

*/