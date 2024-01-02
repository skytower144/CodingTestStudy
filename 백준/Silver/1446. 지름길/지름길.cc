#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<vector<pair<int, int>>> roads(10001);
    vector<int> dp(10001, INT_MAX);
    int shortStart, shortEnd, distance;

    for (int i = 0; i < n; i++) {
        cin >> shortStart >> shortEnd >> distance;
        roads[shortStart].push_back({distance, shortEnd});
    }
    dp[0] = 0;
    for (int i = 0; i < d; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);

        for (const auto [d, pos] : roads[i])
            dp[pos] = min(dp[pos], dp[i] + d);
    }
    cout << dp[d];
    return 0;
}