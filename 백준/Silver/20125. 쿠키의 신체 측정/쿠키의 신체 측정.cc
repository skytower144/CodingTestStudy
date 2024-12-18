#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> grid;
vector<int> bodyParts = { 1, 0, 1, 0, 0, 0, 0 };
pair<int, int> heartPos;

int partIndex = 0;
int n;

void SetBodypartLength(int x, int y)
{
    heartPos = { x, y + 1 };
    int i;

    for (i = heartPos.first - 1; i >= 0 && grid[heartPos.second][i] == '*'; i--)
        bodyParts[1]++;

    for (i = heartPos.first + 1; i < n && grid[heartPos.second][i] == '*'; i++)
        bodyParts[3]++;

    for (i = heartPos.second + 1; i < n && grid[i][heartPos.first] == '*'; i++)
        bodyParts[4]++;

    int j = i;

    for (i = j; i < n && grid[i][heartPos.first - 1] == '*'; i++)
        bodyParts[5]++;

    for (i = j; i < n && grid[i][heartPos.first + 1] == '*'; i++)
        bodyParts[6]++;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    grid = vector<string>(n);

    for (int i = 0; i < n; i++)
        cin >> grid[i];

    for (int i = 0; i < n; i++)
    {
        bool flag = false;

        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                SetBodypartLength(j, i);
                flag = true;
                break;
            }
        }

        if (flag)
            break;
    }

    cout << heartPos.second + 1 << " " << heartPos.first + 1 << '\n';

    for (int i = 0; i < 7; i++)
    {
        if (i == 0 || i == 2)
            continue;

        cout << bodyParts[i] << " ";
    }
    
    return 0;
}