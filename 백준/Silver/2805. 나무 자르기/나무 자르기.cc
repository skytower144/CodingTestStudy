#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<int> trees(n, 0);
    int minLength = 0;
    int maxLength = -1;
    int midLength;
    long long totalLength, answer;

    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        maxLength = max(maxLength, trees[i]);
    }
    while (minLength <= maxLength) {
        totalLength = 0;
        midLength = (minLength + maxLength) / 2;

        for (auto tree : trees)
            totalLength += max(tree - midLength, 0);

        if (totalLength >= m) {
            answer = midLength;
            minLength = midLength + 1;
        }
        else if (totalLength < m) {
            maxLength = midLength - 1;
        }
    }
    cout << answer;
    return 0;
}