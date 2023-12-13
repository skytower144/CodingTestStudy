#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector<int> suggestions(n, 0);
    for (int i = 0; i < n; i++) cin >> suggestions[i];

    sort(suggestions.begin(), suggestions.end());
    
    int exclude = round(n * 0.3 * 0.5);
    double totalDifficulty = 0;

    for (int i = exclude; i < n - exclude; i++)
        totalDifficulty += suggestions[i];
    
    cout << round(totalDifficulty / (n - 2 * exclude));
    return 0;
}