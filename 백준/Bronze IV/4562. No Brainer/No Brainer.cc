#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        int x, y;
        cin >> x >> y;

        if (x >= y)
            cout << "MMM BRAINS" << '\n';
        else
            cout << "NO BRAINS" << '\n';
    }
    return 0;
}