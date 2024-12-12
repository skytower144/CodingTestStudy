#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void Comb(int n, vector<int>& temp, vector<bool>& visited)
{
    if (temp.size() == n)
    {
        for (int i = 0; i < temp.size(); i++)
            cout << temp[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        temp.push_back(i);
        visited[i] = true;

        Comb(n, temp, visited);

        temp.pop_back();
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    vector<bool> visited(n + 1, false);
    vector<int> temp;

    Comb(n, temp, visited);

    return 0;
}