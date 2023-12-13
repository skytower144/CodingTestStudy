#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> liquids(n, 0);
    for (int i = 0; i < n; i++) cin >> liquids[i];

    int left = 0;
    int right = n - 1;
    int liquidSum;
    int leastSum = 2000000000;
    int answer[2] = {0,};

    while (left < right) {
        liquidSum = liquids[left] + liquids[right];

        if (abs(liquidSum) < leastSum) {
            leastSum = abs(liquidSum);
            answer[0] = liquids[left];
            answer[1] = liquids[right];
        }
        if (liquidSum == 0)
            break;
        else if (liquidSum < 0)
            left++;
        else
            right--;
    }
    cout << answer[0] << " " << answer[1];
    return 0;
}