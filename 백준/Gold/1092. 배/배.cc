#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int& a, int& b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;

    cin >> n;
    vector<int> cranes(n, 0);

    for (int i = 0; i < n; i++)
        cin >> cranes[i];

    cin >> m;
    vector<int> crates(m, 0);

    for (int i = 0; i < m; i++)
        cin >> crates[i];

    sort(cranes.begin(), cranes.end(), compare);
    sort(crates.begin(), crates.end());

    if (cranes[0] < crates.back())
    {
        cout << -1;
        return 0;
    }

    int answer = 0;

    while (m > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (m == 0)
                break;

            bool flag = false;

            for (int j = crates.size() - 1; j >= 0; j--)
            {
                if (cranes[i] >= crates[j])
                {
                    m--;
                    crates.erase(crates.begin() + j);
                    break;
                }

                if (j == 0)
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
                break;
        }

        answer++;
    }

    cout << answer;

    return 0;
}