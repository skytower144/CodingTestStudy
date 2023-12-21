#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    vector<int> cards(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> cards[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], dp[i - j] + cards[j]);
    }
    cout << dp[n];
    return 0;
}