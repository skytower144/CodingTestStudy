#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

vector<vector<int>> grid;

int dx1[] = { 0, 1, 1 };
int dy1[] = { 0, 0, 1 };

int dx2[] = { 0, 0,-1 };
int dy2[] = { 0, 1, 1 };

int dx3[] = { 0,-1,-1 };
int dy3[] = { 0, 0,-1 };

int dx4[] = { 0, 0, 1 };
int dy4[] = { 0,-1,-1 };
int N, K;

bool foundSolution = false;

bool CanGo(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= N)
        return false;

    if (grid[y][x] != 0 || grid[y][x] == -1)
        return false;

    return true;
}

bool CanPlace(int x, int y, int dx[], int dy[])
{
    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!CanGo(nx, ny))
            return false;
    }

    return true;
}

void Solution(int ct)
{
    if (ct > K)
    {
        foundSolution = true;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
            cout << '\n';
        }

        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int t = 1; t <= 4; t++)
            {
                if (foundSolution)
                    return;

                int* dx = dx1;
                int* dy = dy1;

                switch (t)
                {
                case 1:
                    dx = dx1;
                    dy = dy1;
                    break;

                case 2:
                    dx = dx2;
                    dy = dy2;
                    break;

                case 3:
                    dx = dx3;
                    dy = dy3;
                    break;

                case 4:
                    dx = dx4;
                    dy = dy4;
                    break;
                }

                if (CanPlace(j, i, dx, dy))
                {
                    for (int c = 0; c < 3; c++)
                        grid[i + dy[c]][j + dx[c]] = ct;

                    Solution(ct + 1);

                    for (int c = 0; c < 3; c++)
                        grid[i + dy[c]][j + dx[c]] = 0;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    int drainX, drainY;
    cin >> drainX >> drainY;

    N = pow(2, n);
    K = N * N / 3;

    drainX -= 1;
    drainY = N - drainY;

    grid = vector<vector<int>>(N, vector<int>(N, 0));
    grid[drainY][drainX] = -1;

    Solution(1);

    return 0;
}