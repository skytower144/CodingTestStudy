#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, l;
    cin >> n >> l;

    vector<int> h(n, 0);
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(h.begin(), h.end());

    for (int i = 0; i < n; i++)
        if (l >= h[i]) l++;

    cout << l;
    return 0;
}