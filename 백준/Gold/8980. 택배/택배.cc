#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, limit, m;
    cin >> n >> limit >> m;

    int startTown, endTown, amount;
    vector<vector<int>> deliveryInfo;

    for (int i = 0; i < m; i++) {
        cin >> startTown >> endTown >> amount;
        deliveryInfo.push_back({endTown, startTown, amount});
    }
    sort(deliveryInfo.begin(), deliveryInfo.end());

    vector<int> timeLine(n + 1, 0);
    int answer = 0;

    for (int i = 0; i < m; i++) {
        startTown = deliveryInfo[i][1];
        endTown = deliveryInfo[i][0];
        amount = deliveryInfo[i][2];

        int mostBoxesAtOnePoint = -1;
    
        for (int j = startTown; j < endTown; j++)
            mostBoxesAtOnePoint = max(mostBoxesAtOnePoint, timeLine[j]);
        
        if (mostBoxesAtOnePoint + amount > limit)
            amount = limit - mostBoxesAtOnePoint;
        
        for (int j = startTown; j < endTown; j++)
            timeLine[j] += amount;

        answer += amount;
    }
    cout << answer;
    return 0;
}