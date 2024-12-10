#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int DURATION = 3;

struct Bomb
{
    int destTime;
    int x;
    int y;
};

vector<vector<char>> grid;
vector<vector<Bomb>> bombGrid;

int r, c, n;
int currentTime;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

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
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (bombGrid[i][j].destTime != currentTime)
                continue;

            int bombX = bombGrid[i][j].x;
            int bombY = bombGrid[i][j].y;

            for (int k = 0; k < 4; k++)
            {
                int nx = bombX + dx[k];
                int ny = bombY + dy[k];

                if (nx < 0 || nx >= c || ny < 0 || ny >= r)
                    continue;

                if (bombGrid[bombY][bombX].destTime == bombGrid[ny][nx].destTime)
                    continue;

                grid[ny][nx] = '.';
                bombGrid[ny][nx] = { -1, };
            }

            grid[bombY][bombX] = '.';
            bombGrid[bombY][bombX] = { -1, };
        }
    }

}

void PlaceBombs()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] != '.')
                continue;

            grid[i][j] = 'O';
            Bomb bomb = { currentTime + DURATION, j, i };
            bombGrid[i][j] = bomb;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> r >> c >> n;

    grid = vector<vector<char>>(r, vector<char>(c, 0));
    bombGrid = vector<vector<Bomb>>(r, vector<Bomb>(c, {-1, }));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            
            if (grid[i][j] == '.')
                continue;

            Bomb bomb = { DURATION, j, i };
            bombGrid[i][j] = bomb;
        }
    }

    for (currentTime = 2; currentTime <= n; currentTime++)
    {
        PlaceBombs();
        Detonate();
    }

    ShowGrid();
    return 0;
}