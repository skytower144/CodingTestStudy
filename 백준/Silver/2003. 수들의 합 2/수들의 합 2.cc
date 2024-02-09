#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> numbers(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int left = 0, right = 0;
    int sum = numbers[0];
    int answer = 0;

    while (true) {
        if (sum < m) {
            right++;
            if (right == n) break;
            sum += numbers[right];
        }
        else {
            if (sum == m) answer++;
            sum -= numbers[left];
            left++;
            if (left == n) break;
        }
    }
    cout << answer;
    return 0;
}