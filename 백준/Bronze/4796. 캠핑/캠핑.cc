#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int l, p, v, days;

    for (int i = 1; ; i++) {
        cin >> l >> p >> v;
        if (l + p + v == 0) break;

        days = (v / p) * l + min(l, v % p);
        cout << "Case " << i << ": " << days << endl;
    }
    return 0;
}