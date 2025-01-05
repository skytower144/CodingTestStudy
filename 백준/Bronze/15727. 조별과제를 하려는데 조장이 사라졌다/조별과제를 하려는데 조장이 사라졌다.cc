#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int l;
    cin >> l;

    int answer = 0;
    answer = l / 5;

    if (l % 5)
        answer++;

    cout << answer;

    return 0;
}