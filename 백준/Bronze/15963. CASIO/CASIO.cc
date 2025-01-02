#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    long long n, m;
    cin >> n >> m;

    cout << bool(n == m);

    return 0;
}