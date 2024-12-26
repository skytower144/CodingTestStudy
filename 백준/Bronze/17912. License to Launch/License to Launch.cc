#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    int launchDate = 0;
    int leastJunk = INT_MAX;

    int junk;

    for (int i = 0; i < n; i++)
    {
        cin >> junk;
        if (leastJunk > junk)
        {
            leastJunk = junk;
            launchDate = i;
        }
    }

    cout << launchDate;

    return 0;
}