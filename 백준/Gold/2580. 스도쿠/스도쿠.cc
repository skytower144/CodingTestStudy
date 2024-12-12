#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9, 0));
vector<vector<bool>> existingRowNums(9, vector<bool>(10, false));
vector<vector<bool>> existingColNums(9, vector<bool>(10, false));
vector<vector<bool>> existingBoxNums(9, vector<bool>(10, false));
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

bool CanPlace(int x, int y, int num)
{
    // 만약 x번째 열에 해당 숫자가 존재한다면
    if (existingColNums[x][num])
        return false;

    if (existingRowNums[y][num])
        return false;

    if (existingBoxNums[y / 3 * 3 + x / 3][num])
        return false;

    return true;
}

void FindSolution(int idx)
{
    if (idx == blanks.size())
    {
        Print();
        exit(0);
    }

    int x = blanks[idx].first;
    int y = blanks[idx].second;
    int boxIdx = y / 3 * 3 + x / 3;
    
    for (int k = 1; k <= 9; k++)
    {
        if (!CanPlace(x, y, k))
            continue;

        sudoku[y][x] = k;
        existingRowNums[y][k] = true;
        existingColNums[x][k] = true;
        existingBoxNums[boxIdx][k] = true;

        FindSolution(idx + 1);

        sudoku[y][x] = 0;
        existingRowNums[y][k] = false;
        existingColNums[x][k] = false;
        existingBoxNums[boxIdx][k] = false;
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