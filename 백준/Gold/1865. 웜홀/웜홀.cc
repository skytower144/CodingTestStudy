#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

bool BelmanFord(int n, vector<vector<int>>& paths, vector<long long>& duration) {
    for (int i = 1; i <= n; i++) {
        for (const auto& path : paths) {
            int from = path[0];
            int to = path[1];
            int time = path[2];
            
            if (duration[to] > duration[from] + time) {
                if (i == n)
                    return true;
                duration[to] = duration[from] + time;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m, w, s, e, t;
        cin >> n >> m >> w;

        vector<vector<int>> paths;
        vector<long long> duration(n + 1, 0);

        for (int i = 0; i < m + w; i++) {
            cin >> s >> e >> t;
            if (i < m) {
                paths.push_back({s, e, t});
                paths.push_back({e, s, t});
            }
            else
                paths.push_back({s, e, -t});
        }
        if (BelmanFord(n, paths, duration))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}