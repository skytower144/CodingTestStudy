#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, a, b;
    cin >> n;

    vector<int> numbers(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> numbers[i];
        dp[i] = dp[i - 1] + numbers[i];
    }
    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << dp[b] - dp[a - 1] << '\n';
    }
    return 0;
}