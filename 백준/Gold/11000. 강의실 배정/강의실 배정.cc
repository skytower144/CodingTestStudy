#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> classes(n);
    for (int i = 0; i < n; i++)
        cin >> classes[i].first >> classes[i].second;

    sort(classes.begin(), classes.end());

    priority_queue<int> endTimes;
    endTimes.push(classes[0].second * -1);

    int answer = 1;
    int earliestEndTime;

    for (int i = 1; i < n; i++) {
        earliestEndTime = endTimes.top() * -1;

        if (classes[i].first >= earliestEndTime)
            endTimes.pop(), answer--;
        
        endTimes.push(classes[i].second * -1);
        answer++;
    }
    cout << answer;
    return 0;
}