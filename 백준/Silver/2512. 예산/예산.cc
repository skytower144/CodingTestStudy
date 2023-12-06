#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, limit, answer;
    cin >> n;

    int minBudget = 0;
    int maxBudget = -1;
    int midBudget;

    vector<int> budgets(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> budgets[i];
        maxBudget = max(maxBudget, budgets[i]);
    }
    cin >> limit;

    while (minBudget <= maxBudget) {
        int total = 0;
        midBudget = (minBudget + maxBudget) / 2;

        for (auto budget : budgets)
            total += min(midBudget, budget);
        
        if (total <= limit) {
            answer = midBudget;
            minBudget = midBudget + 1;
        }
        else
            maxBudget = midBudget - 1;
    }
    cout << answer;
    return 0;
}