#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsCorrect(int target, int size, vector<int>& note) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (note[mid] == target)
            return true;
        if (note[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t, n, m;
    cin >> t;

    for (int k = 0; k < t; k++) {
        cin >> n;
        vector<int> note1(n, 0);
        for (int i = 0; i < n; i++) cin >> note1[i];
        sort(note1.begin(), note1.end());

        cin >> m;
        vector<int> note2(m, 0);
        for (int i = 0; i < m; i++) cin >> note2[i];

        for (const auto num : note2)
            cout << IsCorrect(num, n, note1) << '\n';
    }
    return 0;
}