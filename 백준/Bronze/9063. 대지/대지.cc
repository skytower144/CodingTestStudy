#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    int x, y;
    int maxX, maxY, minX, minY;

    cin >> x >> y;
    maxX = minX = x;
    maxY = minY = y;

    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        maxX = max(maxX, x);
        minX = min(minX, x);
        maxY = max(maxY, y);
        minY = min(minY, y);
    }
    int answer = 0;
    answer = (maxX - minX) * (maxY - minY);

    cout << answer;
    return 0;
}