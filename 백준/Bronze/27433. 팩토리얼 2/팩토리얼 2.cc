#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    unsigned long long answer = 1;

    int n;
    cin >> n;

    for (int i = n; i >= 2; i--)
        answer *= i;

    cout << answer;

    return 0;
}