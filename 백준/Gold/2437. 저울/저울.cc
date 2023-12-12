#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    vector<int> weights(n, 0);

    for (int i = 0; i < n; i++)
        cin >> weights[i];
    
    sort(weights.begin(), weights.end());
    if (weights[0] != 1) {
        cout << 1;
        return 0;
    }
    int possibleEnd = weights[0];

    for (int i = 1; i < n; i++) {
        if (weights[i] > possibleEnd + 1) break;
        possibleEnd += weights[i];
    }
    cout << possibleEnd + 1;
    return 0;
}