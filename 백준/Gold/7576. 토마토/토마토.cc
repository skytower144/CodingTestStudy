#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int m, n;
queue<pair<int, int>> ripe;
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};
int nx, ny;
int days = 1;

int BFS(vector<vector<int>>& storage) {
    int turnedRipe = 0;

    while (!ripe.empty()) {
        int currentCount = ripe.size();

        for (int i = 0; i < currentCount; i++) {
            pair<int, int> ripeTomato = ripe.front();
            ripe.pop();

            for (int j = 0; j < 4; j++) {
                nx = ripeTomato.first + dx[j];
                ny = ripeTomato.second + dy[j];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && storage[ny][nx] == 0) {
                    storage[ny][nx] = days;
                    ripe.push(pair<int, int>(nx, ny));
                    turnedRipe++;
                }
            }
        }
        days++;
    }
    return turnedRipe;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;

    int totalRipe = 0;
    int turnedRipe = 0;
    vector<vector<int>> storage(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> storage[i][j];

            if (storage[i][j] == 0)
                totalRipe++;

            else if (storage[i][j] == 1)
                ripe.push(pair<int, int>(j, i));
        }
    }
    turnedRipe = BFS(storage);
    cout << (turnedRipe == totalRipe ? days-2 : -1);
    return 0;
}