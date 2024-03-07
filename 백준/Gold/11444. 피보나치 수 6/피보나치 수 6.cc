#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> fiboMap;

long long Fibo(long long n) {
    if (n == 0)
        return 0;
    
    if (n == 1 || n == 2)
        return 1;
    
    if (fiboMap.count(n))
        return fiboMap[n];
    
    long long a = n / 2;
    long long b = n - a;

    if (a < b) {
        long long temp = a;
        a = b;
        b = temp;
    }
    long long result = Fibo(a - 1) * Fibo(b) + Fibo(a) * Fibo(b + 1);
    result %= 1000000007;

    fiboMap[n] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    long long n;
    cin >> n;

    cout << Fibo(n);

    return 0;
}