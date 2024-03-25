#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<int> primes(n + 1, 1);
    primes[1] = 0;
    
    for (int i = 2; i <= n; i++) {
        if (!primes[i])
            continue;
        
        for (int j = 2; i * j <= n; j++)
            primes[i * j] = 0;
    }
    for (int i = m; i <= n; i++) {
        if (primes[i])
            cout << i << '\n';
    }
    return 0;
}
