#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>;

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    
    int rects = 0;
    int edges = 4;

    for (int i = 1; i <= n; i++)
    {
        rects += pow(4, i - 1);
        edges += pow(2, i - 1) * (pow(2, i - 1) + 1) * 2;
    }

    cout << rects + edges;

    return 0;
}
