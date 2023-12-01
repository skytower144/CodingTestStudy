#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 0, -1 ,1};
int dy[] = {-1, 1, 0, 0};
int n, nx, ny;

vector<vector<char>> grid;
vector<vector<int>> fullColorVisited;
vector<vector<int>> lessColorVisited;

bool CanGo(bool fullColor, char currentColor, int x, int y) {
    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        return false;
    
    if (fullColor && fullColorVisited[y][x])
        return false;
    
    if (!fullColor && lessColorVisited[y][x])
        return false;
    
    char color = (!fullColor && grid[ny][nx] == 'G') ? 'R' : grid[ny][nx];
    if (currentColor != color) return false;
    
    return true;
}

void BFS(int x, int y, bool fullColor) {
    fullColor ? fullColorVisited[y][x] = 1 : lessColorVisited[y][x] = 1;
    char currentColor = (!fullColor && grid[y][x] == 'G') ? 'R' : grid[y][x];

    queue<pair<int, int>> q;
    pair<int, int> area;
    q.push(pair<int, int>(x, y));

    while (!q.empty()) {
        area = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = area.first + dx[i];
            ny = area.second + dy[i];

            if (CanGo(fullColor, currentColor, nx, ny)) {
                fullColor ? fullColorVisited[ny][nx] = 1 : lessColorVisited[ny][nx] = 1;
                q.push(pair<int, int>(nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    grid = vector<vector<char>>(n, vector<char>(n, 0));
    fullColorVisited = vector<vector<int>>(n, vector<int>(n, 0));
    lessColorVisited = vector<vector<int>>(n, vector<int>(n, 0));

    int fullColorZone = 0;
    int lessColorZone = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!fullColorVisited[i][j]) {
                BFS(j, i, true);
                fullColorZone++;
            }
            if (!lessColorVisited[i][j]) {
                BFS(j, i, false);
                lessColorZone++;
            }
        }
    }
    cout << fullColorZone << " " << lessColorZone;
    return 0;
}