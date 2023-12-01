#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1, 2, 2, 1,-1,-2,-2,-1};
int dy[] = {-2,-1, 1, 2, 2, 1,-1,-2};
vector<vector<int>> visited;

void BFS(int x, int y, int boardSize) {
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x, y));
    pair<int, int> currentPos;
    int nx, ny;

    while (!q.empty()) {
        currentPos = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            x  = currentPos.first, y = currentPos.second;
            nx = x + dx[i], ny = y + dy[i];
            
            if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && !visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push(pair<int, int>(nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int l;
        cin >> l;

        visited = vector<vector<int>>(l, vector<int>(l, 0));
        pair<int, int> start, target;

        cin >> start.first >> start.second;
        cin >> target.first >> target.second;

        visited[start.second][start.first] = 1;
        BFS(start.first, start.second, l);

        cout << visited[target.second][target.first] - 1 << '\n';
    }
    return 0;
}