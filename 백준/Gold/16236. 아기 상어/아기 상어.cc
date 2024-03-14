#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int startX, startY;
int elapsedTime = 0;
int sharkSize = 2;
int consumed = 0;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

vector<vector<int>> grid;
vector<vector<int>> visited;
priority_queue<vector<int>> candidates;

void BFS(int x, int y) {
    vector<vector<int>> visited(n, vector<int>(n, 0)); 
    queue<vector<int>> q;
    int nx, ny, currentTime;

    visited[y][x] = 1;
    q.push({x, y, 0});

    while (!q.empty()) {
        x = q.front()[0];
        y = q.front()[1];
        currentTime = q.front()[2];
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            
            if (visited[ny][nx])
                continue;
            
            if (sharkSize < grid[ny][nx])
                continue;
            
            if (grid[ny][nx] != 0 && sharkSize > grid[ny][nx])
                candidates.push({-(currentTime + 1), -ny, -nx});

            visited[ny][nx] = 1;
            q.push({nx, ny, currentTime + 1});
        }
    }
}
void EatFish() {
    elapsedTime += -candidates.top()[0];
    consumed++;

    if (consumed == sharkSize) {
        consumed = 0;
        sharkSize++;
    }

    startX = -candidates.top()[2];
    startY = -candidates.top()[1];
    grid[startY][startX] = 0;

    candidates = priority_queue<vector<int>>();
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    grid = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 9) {
                startX = j, startY = i;
                grid[i][j] = 0;
            }
        }
    }
    while (true) {
        BFS(startX, startY);
        if (candidates.size() == 0) break;
        EatFish();
    }
    cout << elapsedTime;
    return 0;
}