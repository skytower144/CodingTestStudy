#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// https://velog.io/@sunkyuj/python-%EB%B0%B1%EC%A4%80-17143-%EB%82%9A%EC%8B%9C%EC%99%95

vector<vector<vector<int>>> grid;
vector<vector<vector<int>>> temp;
vector<pair<int, int>> sharks;

int height, width, m;
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, -1, 1, 0, 0};

void MoveShark() {
    int x, y, nx, ny, reducedSpeed = 0;
    int totalSharks = sharks.size();

    for (int i = 0; i < totalSharks; i++) {
        nx = x = sharks[i].first;
        ny = y = sharks[i].second;

        if (grid[y][x][0] == -1)
            continue;

        switch (grid[y][x][1]) {
            case 1:
            case 2:
                reducedSpeed = grid[y][x][0] % (2 * height - 2);
                break;
            case 3:
            case 4:
                reducedSpeed = grid[y][x][0] % (2 * width - 2);
                break;
        }
        for (int s = 0; s < reducedSpeed; s++) {
            nx += dx[grid[y][x][1]];
            ny += dy[grid[y][x][1]];

            if (nx < 0) {
                nx = 1;
                grid[y][x][1] = 3;
            }
            else if (nx >= width) {
                nx = width - 2;
                grid[y][x][1] = 4;
            }
            else if (ny < 0) {
                ny = 1;
                grid[y][x][1] = 2;
            }
            else if (ny >= height) {
                ny = height - 2;
                grid[y][x][1] = 1;
            }
        }
        if (temp[ny][nx][0] == -1) {
            sharks[i] = {nx, ny};
            temp[ny][nx] = grid[y][x];
        }
        else if (temp[ny][nx][2] < grid[y][x][2])
            temp[ny][nx] = grid[y][x];
        
        grid[y][x] = {-1};
    }
    for (const auto& [x, y] : sharks) {
        if (temp[y][x][0] == -1)
            continue;
        
        grid[y][x] = temp[y][x];
        temp[y][x] = {-1};
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> height >> width >> m;

    grid = vector<vector<vector<int>>>(height, vector<vector<int>>(width, {-1}));
    temp = vector<vector<vector<int>>>(height, vector<vector<int>>(width, {-1}));

    int r, c, speed, dir, size;
    int answer = 0;

    while (m--) {
        cin >> r >> c >> speed >> dir >> size;
        sharks.push_back({c - 1, r - 1});
        grid[r - 1][c - 1] = {speed, dir, size};
    }
    for (int col = 0; col < width; col++) {
        for (int h = 0; h < height; h++) {
            if (grid[h][col][0] != -1) {
                answer += grid[h][col][2];
                grid[h][col] = {-1};
                break;
            }
        }
        MoveShark();
    }
    cout << answer;
    return 0;
}