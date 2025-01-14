#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int CheckBingo(vector<vector<int>>& board, int x, int y)
{
    board[y][x] = -1;
    int count = 0;

    bool flag = true;

    for (int i = 0; i < 5; i++)
    {
        if (board[y][i] != -1)
        {
            flag = false;
            break;
        }
    }

    count += flag;
    flag = true;

    for (int i = 0; i < 5; i++)
    {
        if (board[i][x] != -1)
        {
            flag = false;
            break;
        }
    }

    count += flag;
    flag = true;

    if (x == y)
    {
        for (int i = 0; i < 5; i++)
        {
            if (board[i][i] != -1)
            {
                flag = false;
                break;
            }
        }
        count += flag;
    }

    flag = true;

    if (x + y == 4)
    {
        for (int i = 0; i < 5; i++)
        {
            if (board[4 - i][i] != -1)
            {
                flag = false;
                break;
            }
        }
        count += flag;
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    vector<vector<int>> myBingo(5, vector<int>(5, 0));
    vector<vector<int>> bingo(5, vector<int>(5, 0));

    unordered_map<int, pair<int, int>> bingoMap;
    int num;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> num;
            bingoMap[num] = { j, i };
        }
    }

    int count = 0;
    int answer = -1;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> num;
            int x = bingoMap[num].first;
            int y = bingoMap[num].second;

            count += CheckBingo(myBingo, x, y);

            if (count >= 3)
            {
                answer = (5 * i) + (j + 1);
                break;
            }
        }

        if (answer >= 0)
            break;
    }

    cout << answer;

    return 0;
}   