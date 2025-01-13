#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < m; j++)
            grid[i][j] = line[j] - '0';
    }

    int k = min(n, m) + 1;

    while (k--)
    {
        bool flag;

        for (int i = 0; i <= n - k; i++)
        {
            flag = false;

            for (int j = 0; j <= m - k; j++)
            {
                if (grid[i][j] != grid[i][j + k - 1])
                    continue;

                if (grid[i][j] != grid[i + k - 1][j + k - 1])
                    continue;

                if (grid[i][j] != grid[i + k - 1][j])
                    continue;

                flag = true;
                break;
            }

            if (flag)
                break;
        }

        if (flag)
            break;
    }

    cout << k * k;
    return 0;
}   