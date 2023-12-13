#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t, n, m;
    cin >> t;

    for (int k = 0; k < t; k++) {
        cin >> n;
        vector<int> note1(n, 0);
        unordered_map<int, int> numMap;

        for (int i = 0; i < n; i++) {
            cin >> note1[i];
            numMap[note1[i]]++;
        }
        cin >> m;
        vector<int> note2(m, 0);
        for (int i = 0; i < m; i++) cin >> note2[i];

        for (const auto num : note2) {
            if (numMap.count(num)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    return 0;
}