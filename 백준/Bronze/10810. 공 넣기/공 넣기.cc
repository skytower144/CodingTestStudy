#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, i, j, k;
    cin >> n >> m;

    vector<int> basket(n, 0);

    while (m--) {
        cin >> i >> j >> k;

        for (int idx = i - 1; idx < j; idx++)
            basket[idx] = k;
    }
    for (const auto& ball : basket)
        cout << ball << " ";
    return 0;
}