#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    string table;

    cin >> n >> k;
    cin >> table;

    int ate = 0;
    vector<int> burgers(n, 0);
    for (int i = 0; i < n; i++) {
        if (table[i] == 'P') {
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
                if (table[j] == 'H' && burgers[j] == 0) {
                    burgers[j] = 1;
                    ate++;
                    break;
                }
            }
        }
    }
    cout << ate;
    return 0;
}