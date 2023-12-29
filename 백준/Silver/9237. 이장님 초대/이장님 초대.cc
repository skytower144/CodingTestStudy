#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> trees(n, 0);
    for (int i = 0; i < n; i++) cin >> trees[i];

    sort(trees.begin(), trees.end(), greater());
    int answer = 0;

    for (int i = 2; i <= n + 1; i++) {
        answer = max(answer, i + trees[i - 2]);
    }
    cout << answer;
    return 0;
}