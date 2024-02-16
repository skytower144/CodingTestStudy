#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t, x, y;
    cin >> t;

    while (t--) {
        cin >> x >> y;
        cout << x + y << '\n';
    }
    return 0;
}
