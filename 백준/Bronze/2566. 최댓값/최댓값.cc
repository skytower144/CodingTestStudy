#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    vector<vector<int>> grid(9, vector<int>(9, 0));
    int maxNum = -1;
    pair<int, int> maxCod = { 0, 0 };

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> grid[i][j];

            if (maxNum < grid[i][j])
            {
                maxNum = grid[i][j];
                maxCod = { i + 1, j + 1 };
            }
        }
    }

    cout << maxNum << '\n';
    cout << maxCod.first << " " << maxCod.second;

    return 0;
}