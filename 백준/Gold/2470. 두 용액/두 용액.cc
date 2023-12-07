#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    int answer[2] = {0,};
    vector<int> liquids(n, 0);
    for (int i = 0; i < n; i++) cin >> liquids[i];
    sort(liquids.begin(), liquids.end());

    int minDistance = 2000000001;
    int left = 0;
    int right = n - 1;
    int total;

    while (left < right) {
        total = liquids[left] + liquids[right];

        if (minDistance > abs(total)) {
            minDistance = abs(total);
            answer[0] = liquids[left];
            answer[1] = liquids[right];
        }
        if (total < 0) left++;
        else right--;
    }
    cout << answer[0] << " " << answer[1];
    return 0;
}