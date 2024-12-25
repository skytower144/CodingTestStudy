#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    long long prevDp = 0;

    for (int k = 2; k <= n; k++)
        prevDp = (k - 1) + prevDp;

    cout << prevDp;
    return 0;
}