#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    if ((nums[2] - nums[1]) == (nums[1] - nums[0]))
        cout << nums[n - 1] + (nums[1] - nums[0]);
    else
        cout << nums[n - 1] * (nums[1] / nums[0]);   
   
    return 0;
}