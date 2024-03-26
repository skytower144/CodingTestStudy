#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);

    string a, b;
    cin >> a >> b;

    int aSize = a.size();
    int bSize = b.size();

    vector<vector<pair<int, char>>> dp(bSize + 1, vector<pair<int, char>>(aSize + 1));

    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < aSize; j++) {
            if (a[j] == b[i])
                dp[i + 1][j + 1] = {dp[i][j].first + 1, a[j]};
            
            else
                dp[i + 1][j + 1] = dp[i][j + 1].first < dp[i + 1][j].first ? dp[i + 1][j] : dp[i][j + 1];
        }
    }
    int x = aSize;
    int y = bSize;
    string answer = "";

    while (x >= 1 && y >= 1) {
        if (dp[y][x].first == dp[y - 1][x].first)
            y--;
        
        else if (dp[y][x].first == dp[y][x - 1].first)
            x--;
        
        else {
            answer = dp[y][x].second + answer;
            y--;
            x--;
        }
    }
    cout << dp[bSize][aSize].first << '\n';

    if (dp[bSize][aSize].first)
        cout << answer;

    return 0;
}