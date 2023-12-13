#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

bool IsGood(int target, int index, vector<int>& nums) {
    int left = 0;
    int right = n - 1;
    int result;

    while (left < right) {
        if (left == index) left++;
        if (right == index) right--;
        if (left == right) break;

        result = nums[left] + nums[right];

        if (result == target)
            return true;
        if (result > target)
            right--;
        else
            left++;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int answer = 0;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (IsGood(nums[i], i, nums))
            answer++;
    }
    cout << answer;
    return 0;
}