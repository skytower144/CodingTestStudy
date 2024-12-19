#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> cats(n);

    for (int i = 0; i < n; i++)
        cin >> cats[i];

    sort(cats.begin(), cats.end());

    int answer = 0;
    int left = 0;
    int right = cats.size() - 1;

    while (left < right)
    {
        int total = cats[left] + cats[right];

        if (total <= k)
        {
            answer++;
            left++;
            right--;
        }

        else if (total > k)
            right--;
    }

    cout << answer;

    return 0;
}
