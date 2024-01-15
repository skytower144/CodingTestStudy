#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> grid;

bool CanGo(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}
int Poly(int x, int y) {
    int maxPoint = 0, points = 0;
    int nx, ny;
    
    vector<vector<pair<int, int>>> dir = {
        //BLUE
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},

        //ORANGE
        {{0, 0}, {0,-1}, {0,-2}, {1, 0}},
        {{0, 0}, {1, 0}, {2, 0}, {0, 1}},
        {{0, 0}, {0, 1}, {0, 2}, {-1,0}},
        {{0, 0}, {-1,0}, {-2,0}, {0,-1}},

        {{0, 0}, {0,-1}, {0,-2}, {-1,0}},
        {{0, 0}, {1, 0}, {2, 0}, {0,-1}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
        {{0, 0}, {-1,0}, {-2,0}, {0, 1}},

        //PINK
        {{0, 0}, {-1,0}, {1, 0}, {0, 1}},
        {{0, 0}, {0,-1}, {0, 1}, {-1,0}},
        {{0, 0}, {0,-1}, {-1,0}, {1, 0}},
        {{0, 0}, {0,-1}, {0, 1}, {1, 0}},

        //GREEN
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
        {{0, 0}, {1, 0}, {1,-1}, {2,-1}},

        {{0, 0}, {0, 1}, {-1,1}, {-1,2}},
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},

        //YELLOW
        {{0, 0}, {1, 0}, {0, 1}, {1, 1}}
    };
    for (const auto& d : dir) {
        for (const auto& [dx, dy] : d) {
            nx = x + dx;
            ny = y + dy;

            if (!CanGo(nx, ny)) {
                points = 0;
                break;
            }
            points += grid[ny][nx];
        }
        if (points) {
            maxPoint = max(maxPoint, points);
            points = 0;
        }
    }
    return maxPoint;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m, 0));
    int maxPoints = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxPoints = max(maxPoints, Poly(j, i));
        }
    }
    cout << maxPoints;
    return 0;
}