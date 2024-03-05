#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

vector<vector<int>> room;
vector<pair<int, int>> cleanerPos;
pair<int, int> cleanerTop, cleanerBot;
int r, c, t;

void Spread() {
    vector<vector<int>> change(r, vector<int>(c, 0));
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int nx, ny;

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (room[y][x] <= 0)
                continue;
            
            int spreadAmount = room[y][x] / 5;

            for (int i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];

                if (nx < 0 || nx >= c || ny < 0 || ny >= r)
                    continue;
                
                if (room[ny][nx] == -1)
                    continue;
                
                room[y][x] -= spreadAmount;
                change[ny][nx] += spreadAmount;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            room[i][j] += change[i][j];
        }
    }
}
void RunCleaner(int x, int y, bool clockWise) {
    int nx, ny, pushing, pushed;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    pushing = 0;

    if (!clockWise) {
        dy[1] = -1;
        dy[3] = 1;
    }
    for (int i = 0; i < 4; i++) {
        while (true) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= c || ny < 0 || ny >= r)
                break;
            
            if (room[ny][nx] == -1)
                break;
            
            pushed = room[ny][nx];
            room[ny][nx] = pushing;
            pushing = pushed;
            x = nx;
            y = ny;   
        }
    }
}
int GetTotalDust() {
    int totalDust = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (room[i][j] > 0)
                totalDust += room[i][j];
        }
    }
    return totalDust;
}
void PrintRoom() {
    cout << '\n' << t + 1 << " sec : ===========================\n";
    for (auto line : room) {
        for (auto r : line)
            cout << r << " ";
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> r >> c >> t;

    room = vector<vector<int>>(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> room[i][j];

            if (room[i][j] == -1)
                cleanerPos.push_back({j, i});
        }
    }
    cleanerTop = {cleanerPos[0].first, cleanerPos[0].second};
    cleanerBot = {cleanerPos[1].first, cleanerPos[1].second};

    if (cleanerPos[0].second > cleanerPos[1].second) {
        cleanerTop = {cleanerPos[1].first, cleanerPos[1].second};
        cleanerBot = {cleanerPos[0].first, cleanerPos[0].second};
    }
    while (t--) {
        Spread();
        RunCleaner(cleanerTop.first, cleanerTop.second, false);
        RunCleaner(cleanerBot.first, cleanerBot.second, true);
    }
    cout << GetTotalDust();
    return 0;
}