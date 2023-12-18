#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> powers(n, 0);
    vector<int> dp(n, 1);
    int longest = dp[n - 1];

    for (int i = 0; i < n; i++)
        cin >> powers[i];
    
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; i < j; j--) {
            if (powers[i] > powers[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                longest = max(longest, dp[i]);
            }
        }
    }
    cout << n - longest;
    return 0;
}