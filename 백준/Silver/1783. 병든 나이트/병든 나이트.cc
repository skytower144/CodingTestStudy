#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    if (n == 1 || m == 1) {
        cout << 1;
    }
    else if (n < 3 && m < 3) {
        cout << 1;
    }
    else if (n < 3 && m >= 3) {
        if (m % 2) cout << min(4, m / 2 + 1);
        else cout << min(4, m / 2);
    }
    else if (n >= 3 && m < 3) {
        cout << m;
    }
    else if (m < 7) {
        cout << min(m, 4);
    }
    else {
        cout << m - 2;
    }
    return 0;
}