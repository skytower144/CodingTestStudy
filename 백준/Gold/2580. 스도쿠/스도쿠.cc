#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9, 0));
vector<pair<int, int>> blanks;
bool foundSolution = false;

void Print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << sudoku[i][j] << " ";
        cout << '\n';
    }
}

bool CanPlace(int x, int y, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][x] == num || sudoku[y][i] == num)
            return false;
    }

    int startX = x / 3 * 3;
    int startY = y / 3 * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int currentX = startX + j;
            int currentY = startY + i;

            if (sudoku[currentY][currentX] == num)
                return false;
        }
    }

    return true;
}

void FindSolution(int idx)
{
    if (idx == blanks.size())
    {
        foundSolution = true;
        Print();
        exit(0);
    }

    int x = blanks[idx].first;
    int y = blanks[idx].second;
    
    for (int k = 1; k <= 9; k++)
    {
        if (!CanPlace(x, y, k))
            continue;

        if (foundSolution)
            return;

        sudoku[y][x] = k;
        FindSolution(idx + 1);
        sudoku[y][x] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];

            if (sudoku[i][j] == 0)
                blanks.push_back({ j, i });
        }
    }

    FindSolution(0);
    return 0;
}