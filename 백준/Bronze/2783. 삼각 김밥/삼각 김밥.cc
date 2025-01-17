#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    double answer;

    double x, y;
    cin >> x >> y;

    answer = x / y * 1000.0;

    int n;
    cin >> n;

    while (n--)
    {
        cin >> x >> y;
        answer = min(answer, x / y * 1000.0);
    }

    cout << answer;

    return 0;
}   