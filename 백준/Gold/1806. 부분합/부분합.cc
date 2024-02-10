#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, s;
    cin >> n >> s;

    int right = 0;
    int sum = 0;
    int minLength = 100001;
    vector<int> nums(n, 0);

    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    for (int left = 0; left < n; left++) {
        while (sum < s && right < n) {
            sum += nums[right];
            right++;
        }
        if (sum >= s && right - left < minLength)
            minLength = right - left;
        sum -= nums[left];
    }
    if (minLength == 100001)
        minLength = 0;
    cout << minLength;
    return 0;
}