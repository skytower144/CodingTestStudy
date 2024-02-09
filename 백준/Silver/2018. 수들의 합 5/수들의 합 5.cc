#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    int right = 1;
    int sum = 0;
    int answer = 0;

    for (int left = 1; left <= n; left++) {
        while (sum < n) {
            sum += right;
            right++;
        }
        if (sum == n) answer++;
        sum -= left;
    }
    cout << answer;
    return 0;
}