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

    int year;
    int start_e = 0, start_s = 0, start_m = 0;
    
    for (year = 0; start_e != e || start_s != s || start_m != m; year++) {
        start_e = (start_e % ELIMIT) + 1;
        start_s = (start_s % SLIMIT) + 1;
        start_m = (start_m % MLIMIT) + 1;
    }
    cout << year;
    return 0;
}