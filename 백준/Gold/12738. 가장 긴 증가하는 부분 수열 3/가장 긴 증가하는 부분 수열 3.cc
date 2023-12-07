#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, num;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (arr.empty() || arr.back() < num)
            arr.push_back(num);
        else
            *lower_bound(arr.begin(), arr.end(), num) = num;
    }
    cout << arr.size();
    return 0;
}