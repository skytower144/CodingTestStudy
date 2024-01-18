#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> duration(n + 1, 0);
        vector<int> dp(n + 1, 0);
        vector<vector<int>> graph(n + 1);
        vector<int> degree(n + 1, 0);
        queue<int> q;

        int x, y;
        int lastBuilding;

        for (int i = 1; i <= n; i++)
            cin >> duration[i];
        
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            graph[x].push_back(y);
            degree[y]++;
        }
        cin >> lastBuilding;

        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                q.push(i);
                dp[i] = duration[i];
            }
        }
        while (!q.empty()) {
            int popped = q.front();
            q.pop();

            for (const auto& neighbor : graph[popped]) {
                degree[neighbor]--;
                dp[neighbor] = max(dp[neighbor], dp[popped] + duration[neighbor]);

                if (degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        cout << dp[lastBuilding] << '\n';
    }

    return 0;
}