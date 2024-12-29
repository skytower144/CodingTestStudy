#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    if (a[1] != b[1])
        return a[1] > b[1];

    if (a[2] != b[2])
        return a[2] > b[2];

    if (a[3] != b[3])
        return a[3] > b[3];

    return a[0] < b[0];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> info;
    int country, gold, silver, bronze;

    for (int i = 0; i < n; i++)
    {
        cin >> country >> gold >> silver >> bronze;
        info.push_back({ country, gold, silver, bronze });
    }

    sort(info.begin(), info.end(), compare);
    int rank = 0;

    for (int i = 0; i < n; i++)
    {
        if (info[i][0] != k)
            continue;

        rank = i + 1;
        int j = i;

        while (j > 0 && info[j - 1][1] == info[j][1] && info[j - 1][2] == info[j][2] && info[j - 1][3] == info[j][3])
        {
            rank--;
            j--;
        }

        break;
    }

    cout << rank;

    return 0;
}