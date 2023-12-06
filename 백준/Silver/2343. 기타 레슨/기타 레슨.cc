#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long n, m;
    cin >> n >> m;

    long long left = 1;
    long long right = 1000000000;

    vector<long long> classes(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> classes[i];
        left = max(left, classes[i]);
    }
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sumLength = 0;
        long long count = 0;
    
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