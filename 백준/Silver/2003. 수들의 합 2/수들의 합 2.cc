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
    int right = 0;
    int sum = 0;
    int answer = 0;

    for (int left = 0; left < n; left++) {
        while (sum < m && right < n) {
            sum += numbers[right];
            right++;
        }
        if (sum == m)
            answer++;
        sum -= numbers[left];
    }
    cout << answer;
    return 0;
}