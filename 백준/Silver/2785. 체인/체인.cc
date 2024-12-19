#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    vector<int> chains(n);

    for (int i = 0; i < n; i++)
        cin >> chains[i];

    sort(chains.begin(), chains.end());

    int gaps = n - 1;
    int links = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (links + chains[i] < gaps)
        {
            links += chains[i];
            gaps--;
        }
        else
        {
            links += (gaps - links);
            break;
        }
    }

    cout << links;
    return 0;
}
