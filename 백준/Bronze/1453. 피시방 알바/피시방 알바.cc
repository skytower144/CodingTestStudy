#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    int answer = 0;
    vector<bool> seats(101, false);

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (!seats[num])
        {
            seats[num] = true;
            continue;
        }

        answer++;
    }

    cout << answer;

    return 0;
}   