#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int ax, ay, az;
    int bx, by, bz;
    int cx, cy, cz;

    cin >> ax >> ay >> az;
    cin >> cx >> cy >> cz;

    bx = cx - az;
    by = cy / ay;
    bz = cz - ax;

    cout << bx << " " << by << " " << bz;

    return 0;
}