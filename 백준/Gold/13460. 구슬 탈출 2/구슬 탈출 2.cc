#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<char>> grid;
int goalX, goalY;

int n, m;
int answer = -1;
int visited[10][10][10][10];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool CanGo(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n)
        return false;

    if (grid[y][x] == '#')
        return false;   

    return true;
}

void BFS(pair<int, int> redPos, pair<int, int> bluePos) {
    queue<vector<int>> q;
    int redX, redY, blueX, blueY;
    int redNx, redNy, blueNx, blueNy;
    int turns = 0;

    visited[redPos.first][redPos.second][bluePos.first][bluePos.second] = 1;
    q.push({redPos.first, redPos.second, bluePos.first, bluePos.second, turns});

    while (!q.empty()) {
        redX = q.front()[0];
        redY = q.front()[1];
        blueX = q.front()[2];
        blueY = q.front()[3];
        turns = q.front()[4];
        q.pop();

        if (redX == goalX && redY == goalY)
            continue;

        if (blueX == goalX && blueY == goalY)
            continue;

        for (int i = 0; i < 4; i++) {
            redNx = redX;
            redNy = redY;
            blueNx = blueX;
            blueNy = blueY;

            int redDistance = 0;
            int blueDistance = 0;

            bool redStop = false;
            bool blueStop = false;

            bool redGoal = false;
            bool blueGoal = false;

            while (true) {
                if (!redStop) {
                    redNx += dx[i];
                    redNy += dy[i];
                    redDistance++;
                }
                if (!blueStop) {
                    blueNx += dx[i];
                    blueNy += dy[i];
                    blueDistance++;
                }
                if (!CanGo(redNx, redNy)) {
                    redNx -= dx[i];
                    redNy -= dy[i];
                    redStop = true;
                    redDistance--;
                }
                if (!CanGo(blueNx, blueNy)) {
                    blueNx -= dx[i];
                    blueNy -= dy[i];
                    blueStop = true;
                    blueDistance--;
                }
                if (redNx == goalX && redNy == goalY)
                    redGoal = true;

                if (blueNx == goalX && blueNy == goalY)
                    blueGoal = true;
                
                if (redStop && blueStop)
                    break;
            }
            if (blueGoal)
                continue;
            
            if (redGoal && !blueGoal) {
                answer = turns + 1;
                return;
            }
            if (redNx == blueNx && redNy == blueNy) {
                if (redDistance < blueDistance) {
                    blueNx -= dx[i];
                    blueNy -= dy[i];
                }
                else {
                    redNx -= dx[i];
                    redNy -= dy[i];
                }
            }
            if (visited[redNx][redNy][blueNx][blueNy])
                continue;
            
            visited[redNx][redNy][blueNx][blueNy] = 1;
            q.push({redNx, redNy, blueNx, blueNy, turns + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    grid = vector<vector<char>>(n);

    string line;
    pair<int, int> redPos, bluePos;

    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < m; j++) {
            grid[i].push_back(line[j]);

            if (line[j] == 'R')
                redPos = {j, i};
            
            else if (line[j] == 'B')
                bluePos = {j, i};
            
            else if (line[j] == 'O') {
                goalX = j;
                goalY = i;
            }
        }
    }
    BFS(redPos, bluePos);

    if (answer > 10)
        answer = -1;
    cout << answer;
    return 0;
}