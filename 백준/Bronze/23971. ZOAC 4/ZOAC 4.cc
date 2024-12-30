#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int h, w, n, m;
    cin >> h >> w >> n >> m;

    int xCount = 0, yCount = 0;

    for (int i = 0; i < w; i += m + 1)
        xCount++;

    for (int i = 0; i < h; i += n + 1)
        yCount++;

    int answer = xCount * yCount;
    cout << answer;

    return 0;
}