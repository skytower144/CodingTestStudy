#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int time;
    int total = 0;

    for (int i = 0; i < 4; i++)
    {
        cin >> time;
        total += time;
    }

    int minutes = total / 60;
    int seconds = total % 60;

    cout << minutes << '\n' << seconds;

    return 0;
}