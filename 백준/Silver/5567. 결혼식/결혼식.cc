#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> grid;
vector<bool> visited, visited2;
int answer = 0;

unordered_map<int, bool> friendMap;

void FindFriends(int num, int depth)
{
    if (depth >= 2)
        return;

    for (int friendNum : grid[num])
    {
        if (!visited[friendNum])
        {
            friendMap[friendNum] = true;

            visited[friendNum] = true;
            FindFriends(friendNum, depth + 1);
            visited[friendNum] = false;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    grid = vector<vector<int>>(n + 1);
    visited = vector<bool>(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;

        grid[num1].push_back(num2);
        grid[num2].push_back(num1);
    }

    if (grid[1].empty())
    {
        cout << answer;
        return 0;
    }

    visited[1] = true;
    FindFriends(1, 0);

    answer = friendMap.size();
    cout << answer;
    return 0;
}