#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> prices(n);

        for (int i = 0; i < n; i++)
            cin >> prices[i];

        vector<int> stack;
        long long sum = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (!stack.empty() && stack[0] < prices[i])
            {
                for (int j = 1; j < stack.size(); j++)
                    sum += stack[0] - stack[j];

                stack.clear();
            }

            stack.push_back(prices[i]);
        }

        for (int j = 1; j < stack.size(); j++)
            sum += stack[0] - stack[j];

        cout << sum << '\n';
    }

    return 0;
}