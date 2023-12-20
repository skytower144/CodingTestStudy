#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fibCount = 0;
int fiboCount = 0;

int fib(int n) {
    if (n == 1 || n == 2) {
        fibCount++;
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
    int dp[41] = {0, };
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        fiboCount++;
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    fib(n);
    fibonacci(n);

    cout << fibCount << " " << fiboCount;
    return 0;
}