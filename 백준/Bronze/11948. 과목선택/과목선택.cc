#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    vector<int> first(4);
    vector<int> second(2);

    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < 4; i++)
    {
        cin >> first[i];
        sum1 += first[i];
    }

    for (int i = 0; i < 2; i++)
    {
        cin >> second[i];
        sum2 += second[i];
    }

    sort(first.begin(), first.end(), greater<int>());
    sort(second.begin(), second.end(), greater<int>());

    sum1 -= first.back();
    sum2 -= second.back();

    cout << sum1 + sum2;
    return 0;
}