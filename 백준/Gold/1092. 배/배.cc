#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

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
    sort(crates.begin(), crates.end(), compare);

    if (cranes[0] < crates[0])
    {
        cout << -1;
        return 0;
    }

    vector<int> count(n, 0);
    int answer = 0;
    
    for (int i = 0; i < m; i++)
    {
        int carriedLeastIndex = 0;

        for (int j = 0; j < n; j++)
        {
            if (cranes[j] >= crates[i] && count[carriedLeastIndex] > count[j])
                carriedLeastIndex = j;
        }

        count[carriedLeastIndex]++;
        answer = max(answer, count[carriedLeastIndex]);
    }

    cout << answer;

    return 0;
}