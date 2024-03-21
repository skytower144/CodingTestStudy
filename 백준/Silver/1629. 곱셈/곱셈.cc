#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

long long a, b, c;

long long Multiply(long long n, long long x) {
    if (x == 0)
        return 1;
    
    long long split = Multiply(n, x / 2);

    if (x % 2 == 0)
        return (split * split) % c;
    else
        return ((split * split % c) * n) % c;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> a >> b >> c;

    cout << Multiply(a, b);
    return 0;
}