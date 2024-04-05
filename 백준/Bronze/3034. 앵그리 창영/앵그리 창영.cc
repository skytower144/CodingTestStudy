#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, w, h;
    cin >> n >> w >> h;

    double side, length;
    double longestLimit = max(w, h);
    longestLimit = max(longestLimit, sqrt(w * w + h * h));

    while (n--) {
        cin >> length;

        if (length <= longestLimit)
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';
    }
    return 0;
}