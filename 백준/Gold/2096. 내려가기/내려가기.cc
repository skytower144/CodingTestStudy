#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    vector<vector<int>> maxGrid(2, vector<int>(3, 0));
    vector<vector<int>> minGrid(2, vector<int>(3, 0));

    cin >> n;
    cin >> maxGrid[0][0] >> maxGrid[0][1] >> maxGrid[0][2];

    minGrid[0][0] = maxGrid[0][0];
    minGrid[0][1] = maxGrid[0][1];
    minGrid[0][2] = maxGrid[0][2];

    for (int i = 1; i < n; i++) {
        cin >> maxGrid[1][0] >> maxGrid[1][1] >> maxGrid[1][2];
        minGrid[1][0] = maxGrid[1][0];
        minGrid[1][1] = maxGrid[1][1];
        minGrid[1][2] = maxGrid[1][2];

        maxGrid[1][0] += max(maxGrid[0][0], maxGrid[0][1]);
        maxGrid[1][1] += max(maxGrid[0][0], max(maxGrid[0][1], maxGrid[0][2]));
        maxGrid[1][2] += max(maxGrid[0][1], maxGrid[0][2]);

        minGrid[1][0] += min(minGrid[0][0], minGrid[0][1]);
        minGrid[1][1] += min(minGrid[0][0], min(minGrid[0][1], minGrid[0][2]));
        minGrid[1][2] += min(minGrid[0][1], minGrid[0][2]);

        maxGrid[0][0] = maxGrid[1][0];
        maxGrid[0][1] = maxGrid[1][1];
        maxGrid[0][2] = maxGrid[1][2];

        minGrid[0][0] = minGrid[1][0];
        minGrid[0][1] = minGrid[1][1];
        minGrid[0][2] = minGrid[1][2];
    }
    int maxNum = max(maxGrid[0][0], max(maxGrid[0][1], maxGrid[0][2]));
    int minNum = min(minGrid[0][0], min(minGrid[0][1], minGrid[0][2]));

    cout << maxNum << " " << minNum;
    return 0;
}