#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int grid[100][100];
const int INF = INT_MAX / 2;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 0)
                grid[i][j] = INF;
        }
    }
    // 플로이드 마샬 알고리즘 이용하기
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == INF) cout << "0 ";
            else cout << "1 ";
        }
        cout << "\n";
    }
    return 0;
}