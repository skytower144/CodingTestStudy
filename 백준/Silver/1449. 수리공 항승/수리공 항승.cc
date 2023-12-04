#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l;
    cin >> n >> l;

    vector<int> leaking(n, 0);
    vector<int> taped(1001, 0);
    int answer = 0;

    for (int i = 0; i < n; i++) cin >> leaking[i];
    sort(leaking.begin(), leaking.end());

    for (const auto pos : leaking) {
        if (taped[pos]) continue;

        for (int i = 0; i < l; i++) {
            if (pos + i > 1000) break;
            taped[pos + i] = 1;
        }
        answer++;
    }
    cout << answer;
    return 0;
}