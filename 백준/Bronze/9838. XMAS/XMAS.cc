#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    unordered_map<int, int> giftMap;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        giftMap[num] = i;
    }

    for (int i = 1; i <= n; i++)
        cout << giftMap[i] << '\n';

    return 0;
}   