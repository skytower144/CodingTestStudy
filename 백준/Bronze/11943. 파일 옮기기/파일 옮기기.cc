#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << min(a + d, b + c);

    return 0;
}   