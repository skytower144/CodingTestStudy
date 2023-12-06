#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    int left = 1;
    int right = 1000000000;

    vector<int> classes(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> classes[i];
        left = max(left, classes[i]);
    }
    while (left <= right) {
        int mid = (left + right) / 2;
        int sumLength = 0;
        int count = 0;
    
        for (const auto length : classes) {
            if (sumLength + length <= mid)
                sumLength += length;
            else {
                sumLength = length;
                count++;
            }
        }
        count++;

        if (count <= m)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << left;
    return 0;
}