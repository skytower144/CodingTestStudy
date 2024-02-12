#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> visitors(n, 0);
    for (int i = 0; i < n; i++)
        cin >> visitors[i];
    
    int left = 0;
    int right = x - 1;
    int sum = 0;

    for (int i = left; i <= right; i++)
        sum += visitors[i];
    
    int maxVisitors = sum;
    int count = 0;
    
    while (right < n) {
        if (maxVisitors < sum) {
            maxVisitors = sum;
            count = 1;
        }
        else if (maxVisitors == sum)
            count++;
        sum -= visitors[left];
        left++;

        right++;
        if (right == n) break;
        sum += visitors[right];
    }
    if (maxVisitors == 0)
        cout << "SAD";
    else
        cout << maxVisitors << '\n' << count;
    return 0;
}