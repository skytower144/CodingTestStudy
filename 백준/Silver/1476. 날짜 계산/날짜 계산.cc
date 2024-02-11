#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const int ELIMIT = 15;
    const int SLIMIT = 28;
    const int MLIMIT = 19;

    int e, s, m;
    cin >> e >> s >> m;

    int year = 0;
    int start_e = 0, start_s = 0, start_m = 0;
    
    while (true) {
        start_e++;
        start_s++;
        start_m++;

        if (start_e > ELIMIT) start_e = 1;
        if (start_s > SLIMIT) start_s = 1;
        if (start_m > MLIMIT) start_m = 1;

        year++;
        if (start_e == e && start_s == s && start_m == m) break;
    }
    cout << year;
    return 0;
}