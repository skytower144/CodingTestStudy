#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<int, bool> trainMap;
    vector<int> trains(n, 0);
    int command, t, x;

    while (m--)
    {
        cin >> command >> t;
        t--;

        if (command <= 2)
        {
            cin >> x;
            x--;
        }

        switch (command)
        {
        case 1:
            trains[t] |= (1 << x);
            break;

        case 2:
            trains[t] &= ~(1 << x);
            break;

        case 3:
            trains[t] &= ~(1 << 19);
            trains[t] = trains[t] << 1;
            break;

        case 4:
            trains[t] = trains[t] >> 1;
            break;
        }
    }

    for (int i = 0; i < n; i++)
        trainMap[trains[i]] = true;

    cout << trainMap.size() << endl;
    return 0;
}