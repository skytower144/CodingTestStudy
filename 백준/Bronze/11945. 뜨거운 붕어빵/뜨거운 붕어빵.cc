#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    string shape;

    for (int i = 0; i < n; i++)
    {
        cin >> shape;
        reverse(shape.begin(), shape.end());
        cout << shape << '\n';
    }
    return 0;
}