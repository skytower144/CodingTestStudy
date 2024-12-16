#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> prices(m, 0);

    for (int i = 0; i < m; i++)
        cin >> prices[i];

    sort(prices.begin(), prices.end());

    int maxProfit = -1;
    int maxPrice = -1;


    for (int i = 0; i < m; i++)
    {
        int profit = prices[i] * min(n, (m - i));

        if (maxProfit < profit)
        {
            maxProfit = profit;
            maxPrice = prices[i];
        }
    }

    cout << maxPrice << " " << maxProfit << '\n';
    return 0;
}