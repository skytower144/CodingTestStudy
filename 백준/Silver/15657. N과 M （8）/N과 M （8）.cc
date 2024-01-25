#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;

void Backtrack(vector<int> temp, int index, int count) {
    if (count == m) {
        for (const auto& num : temp)
            cout << num << " ";
        cout << '\n';
        return;
    }
    for (int i = index; i < n; i++) {
        temp.push_back(nums[i]);
        Backtrack(temp, i, count + 1);
        temp.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    nums = vector<int>(n, 0);
    vector<int> temp;

    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    Backtrack(temp, 0, 0);

    return 0;
}