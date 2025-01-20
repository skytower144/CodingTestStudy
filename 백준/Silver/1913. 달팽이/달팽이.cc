#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    int k = n / 2;
    int i = 0;

    int num = n * n;
    int x = 0, y = -1;
    pair<int, int> target;

    while (num >= 1)
    {
        x = x + dx[i];
        y = y + dy[i];
        grid[y][x] = num;

        if (num == m)
            target = { y + 1, x + 1 };

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[ny][nx] > 0)
            i = (i + 1) % 4;

        num--;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << '\n';
    }
    
    cout << target.first << " " << target.second;

    return 0;
}