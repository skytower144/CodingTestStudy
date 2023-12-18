#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    if (n == 1)
        cout << 1;
    
    else if (n == 2)
        cout << min((m + 1) / 2, 4);
    
    else if (m < 7)
        cout << min(m, 4);
    
    else
        cout << m - 2;
    return 0;
}