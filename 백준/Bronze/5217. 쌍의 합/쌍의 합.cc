#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;

        vector<pair<int, int>> pairs;
        for (int j = 1; ; j++) {
            if (j < num - j)
                pairs.push_back({j, num - j});
            else
                break;
        }
        int size = pairs.size();
        cout << "Pairs for " << num << ": ";

        for (int i = 0; i < size; i++) {
            cout << pairs[i].first << " " << pairs[i].second;

            if (i < size - 1)
                cout << ", ";
        }
        cout << '\n';
    }

    return 0;
}