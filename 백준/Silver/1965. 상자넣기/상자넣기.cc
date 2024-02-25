#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n, 1);
    vector<int> nums(n, 0);

    int maxNum = 1;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];

        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                maxNum = max(maxNum, dp[i]);
            }
        }
    }
    cout << maxNum;
    return 0;
}