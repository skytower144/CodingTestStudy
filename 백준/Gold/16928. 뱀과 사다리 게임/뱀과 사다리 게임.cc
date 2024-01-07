#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> ladders(101, -1);
    vector<int> snakes(101, -1);
    int u, v;

    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        ladders[u] = v;
    } 
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        snakes[u] = v;
    }
    vector<int> visited(101, 0);
    vector<int> rolls(101, INT_MAX);
    queue<int> q;
    int dx[] = {1, 2, 3, 4, 5, 6};
    int nx;

    q.push(1);
    rolls[1] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (const auto d : dx) {
            nx = x + d;
            if (nx > 100)
                continue;
            
            if (ladders[nx] != -1)
                nx = ladders[nx];
            
            if (snakes[nx] != -1)
                nx = snakes[nx];
            
            if (rolls[x] + 1 < rolls[nx] && !visited[nx]) {
                visited[nx] = 1;
                rolls[nx] = rolls[x] + 1;
                q.push(nx);
            }
        }
    }
    cout << rolls[100];
    return 0;
}