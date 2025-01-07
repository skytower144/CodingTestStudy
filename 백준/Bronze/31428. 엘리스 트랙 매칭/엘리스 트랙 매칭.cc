#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    vector<int> tracks(26, 0);
    char c;

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        tracks[c - 'A']++;
    }

    char myTrack;
    cin >> myTrack;

    cout << tracks[myTrack - 'A'];

    return 0;
}   