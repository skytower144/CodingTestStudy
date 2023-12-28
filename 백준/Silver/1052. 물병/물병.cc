#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int GetOnes(int n) {
    int count = 0;

    while (n > 0) {
        if (n % 2) count++;
        n /= 2;
    }
    return count;
}
int main() {
    // https://www.acmicpc.net/source/70433469
    // 비트마스킹

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    int answer = 0;
    for (int i = 1; ; i *= 2) {
        int ones = GetOnes(n);
        if (ones <= k) break;

        if ((n & i) == i) {
            n += i;
            answer += i;
        }
    }
    cout << answer;
    return 0;
}