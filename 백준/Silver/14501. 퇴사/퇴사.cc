#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> schedule;
vector<int> dp;
int answer = -1;

void S(int day, int money) {
    if (day > n) {
        if (day == n + 1)
            answer = max(answer, money);
        return;
    }
    S(day + schedule[day][0], money + schedule[day][1]);
    S(day + 1, money);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    schedule = vector<vector<int>>(n + 1, vector<int>(2, 0));
    dp = vector<int>(n + 1, 0);

    for (int i = 1; i < n + 1; i++)
        cin >> schedule[i][0] >> schedule[i][1];
    
    S(1, 0);
    cout << answer;

    return 0;
}