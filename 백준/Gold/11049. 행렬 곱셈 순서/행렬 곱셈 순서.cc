#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, r, c;
    cin >> n;

    vector<pair<int, int>> matrix;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        cin >> r >> c;
        matrix.push_back({r, c});
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            int minCount = INT_MAX;

            for (int k = j; k <= j + i - 2; k++) {
                int leftS = j, leftE = k;
                int rightS = k + 1, rightE = j + i - 1; 
                
                int a = matrix[leftS].first;
                int b = matrix[leftE].second;
                int c = matrix[rightE].second;

                minCount = min(minCount, dp[leftS][leftE] + dp[rightS][rightE] + a * b * c);
            }
            dp[j][j + i - 1] = minCount;
        }
    }
    cout << dp[0][n - 1];
    return 0;
}