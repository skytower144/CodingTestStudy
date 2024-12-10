#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<char>> grid;
queue<pair<int, int>> q;

int r, c, n;
int currentTime;

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, -1, 1, 0, 0 };

void ShowGrid()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << grid[i][j];
        cout << '\n';
    }
}

void Detonate()
{
    while (!q.empty())
    {
        int bombX = q.front().first;
        int bombY = q.front().second;
        q.pop();

        for (int k = 0; k < 5; k++)
        {
            int nx = bombX + dx[k];
            int ny = bombY + dy[k];

            if (nx < 0 || nx >= c || ny < 0 || ny >= r)
                continue;

            grid[ny][nx] = '.';
        }
    }
}

void RegisterBombs()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 'O')
                q.push({ j, i });
            else
                grid[i][j] = 'O';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> r >> c >> n;
    grid = vector<vector<char>>(r, vector<char>(c, 'O'));

    if (n % 2 == 0)
    {
        ShowGrid();
        return 0;
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    }

    if (n <= 1)
    {
        ShowGrid();
        return 0;
    }

    if (n > 5)
    {
        n %= 4;
        if (n <= 1)
            n += 4;
    }

    for (currentTime = 2; currentTime <= n; currentTime++)
    {
        if (currentTime % 2 == 0)
            RegisterBombs();
        else
            Detonate();
    }

    ShowGrid();
    return 0;
}