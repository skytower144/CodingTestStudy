#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> basket;
    for (int i = 0; i <= n; i++)
        basket.push_back(i);
    
    while (m--) {
        int i, j;
        cin >> i >> j;

        int temp = basket[i];
        basket[i] = basket[j];
        basket[j] = temp;
    }
    for (int i = 1; i <= n; i++)
        cout << basket[i] << " ";

    return 0;
}
