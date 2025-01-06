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

    vector<int> menu(n, 0);

    for (int i = 0; i < n; i++)
        cin >> menu[i];

    int m;
    cin >> m;

    int answer = 0;

    while (m--)
    {
        int num;
        cin >> num;

        answer += menu[num - 1];
    }

    cout << answer;
    return 0;
}