#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sudoku[9][9];
bool existingRowNums[9][10];
bool existingColNums[9][10];
bool existingBoxNums[9][10];
vector<pair<int, int>> blanks;

void Print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << sudoku[i][j] << " ";
        cout << '\n';
    }
}

bool FindSolution(int idx)
{
    if (idx == blanks.size())
    {
        Print();
        return true;
    }

    int x = blanks[idx].first;
    int y = blanks[idx].second;
    int boxIdx = y / 3 * 3 + x / 3;

    for (int k = 1; k <= 9; k++)
    {
        if (existingColNums[x][k] || existingRowNums[y][k] || existingBoxNums[boxIdx][k])
            continue;

        sudoku[y][x] = k;
        existingRowNums[y][k] = true;
        existingColNums[x][k] = true;
        existingBoxNums[boxIdx][k] = true;

        if (FindSolution(idx + 1))
            return true;

        sudoku[y][x] = 0;
        existingRowNums[y][k] = false;
        existingColNums[x][k] = false;
        existingBoxNums[boxIdx][k] = false;
    }

    return false;
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
            else
            {
                existingRowNums[i][sudoku[i][j]] = true;
                existingColNums[j][sudoku[i][j]] = true;
                existingBoxNums[i / 3 * 3 + j / 3][sudoku[i][j]] = true;
            }
        }
    }

    FindSolution(0);
    return 0;
}