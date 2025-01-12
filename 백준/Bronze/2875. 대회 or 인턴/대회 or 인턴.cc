#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int girl = 0;
    int boy = 0;
    int diff = 0;
    int group = 0;

    while (girl <= n && boy <= m)
    {
        girl += 2;
        boy += 1;
        group++;

        diff = n - girl + m - boy;

        if (diff <= k)
            break;
    }

    if (diff != k)
        group--;

    cout << group;

    return 0;
}   