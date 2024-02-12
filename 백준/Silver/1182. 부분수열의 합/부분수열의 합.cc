#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
int answer = 0;

void Backtrack(vector<int>& nums, vector<int>& temp, int sum, int idx) {
    for (int i = idx; i < n; i++) {
        temp.push_back(nums[i]);
        Backtrack(nums, temp, sum + nums[i], i + 1);
        temp.pop_back();
    }
    if (temp.size() > 0 && sum == s)
        answer++;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> s;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> temp;
    Backtrack(nums, temp, 0, 0);
    
    cout << answer;
    return 0;
}