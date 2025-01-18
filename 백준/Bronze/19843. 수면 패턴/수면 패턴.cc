#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    unordered_map<string, int> dateMap = {
        {"Mon", 0},
        {"Tue", 1},
        {"Wed", 2},
        {"Thu", 3},
        {"Fri", 4}
    };

    int t, n;
    cin >> t >> n;

    string d1, d2;
    int h1, h2;

    int sumHour = 0;

    while (n--)
    {
        cin >> d1 >> h1 >> d2 >> h2;

        int days = dateMap[d2] - dateMap[d1];

        if (days == 0)
        {
            sumHour += h2 - h1;
            continue;
        }

        days--;
        sumHour += (24 - h1) + (days * 24) + h2;
    }

    int answer = t - sumHour;

    if (answer <= 0)
        answer = 0;
    else
    {
        if (answer > 48)
            answer = -1;
    }

    cout << answer;

    return 0;
}   