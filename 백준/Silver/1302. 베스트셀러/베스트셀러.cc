#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    string book;
    map<string, int> salesMap;
    int maxSold = -1;

    for (int i = 0; i < n; i++) {
        cin >> book;
        salesMap[book]++;
        maxSold = max(maxSold, salesMap[book]);
    }
    for (const auto& [book, sold] : salesMap) {
        if (sold == maxSold) {
            cout << book << '\n';
            break;
        }
    }
    return 0;
}