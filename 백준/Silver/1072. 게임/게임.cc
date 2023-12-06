#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    long long total, won;
    cin >> total >> won;

    long long currentWinRate = floor((double)won * 100 / total);
    long long minWon = won;
    long long maxWon = 2000000000;
    long long midWon, winRate;
    long long answer = -1;

    while (minWon <= maxWon) {
        midWon = (minWon + maxWon) / 2;
        winRate = floor((double)midWon * 100 / (total + midWon - won));

        if (winRate > currentWinRate) {
            answer = midWon - won;
            maxWon = midWon - 1;
        }
        else
            minWon = midWon + 1;
    }
    cout << answer;
    return 0;
}