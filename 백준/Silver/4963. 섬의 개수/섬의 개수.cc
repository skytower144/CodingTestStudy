#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& world, vector<vector<int>>& visited, queue<pair<int, int>>& q, int w, int h) {
    pair<int, int> block;
    int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
    int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};
    int nx, ny;

    while (!q.empty()) {
        block = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            nx = block.first + dx[i];
            ny = block.second + dy[i];

            if (nx >= 0 && nx < w && ny >= 0 && ny < h && world[ny][nx] != 0 && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push(pair<int, int>(nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int w, h;
    
    while (true) {
        cin >> w >> h;
        if (w + h == 0) break;

        vector<vector<int>> world(h, vector<int>(w, 0));
        vector<vector<int>> visited(h, vector<int>(w, 0));
        queue<pair<int, int>> q;
        int islandCount = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                cin >> world[i][j];
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (world[i][j] && !visited[i][j]) {
                    visited[i][j] = 1;
                    q.push(pair<int, int>(j, i));
                    BFS(world, visited, q, w, h);
                    islandCount++;
                }
            }
        }
        cout << islandCount << endl;
    }
    return 0;
}