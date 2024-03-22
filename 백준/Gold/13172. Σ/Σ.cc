#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-13172%EB%B2%88-%CE%A3-CC

const long long C = 1000000007;

long long Multiply(long long n, long long x) {
    if (x == 0)
        return 1;
    
    long long split = Multiply(n, x / 2);

    if (x % 2 == 0)
        return (split * split) % C;
    else
        return ((split * split % C) * n) % C;
}

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    long long m, n, s, gcd, answer = 0;
    cin >> m;
    
    while (m--) {
        cin >> n >> s;
        gcd = GCD(n, s);
        
        s /= gcd;
        n /= gcd;

        answer += s * Multiply(n, C - 2) % C;
        answer %= C;
    }
    cout << answer;
    return 0;
}