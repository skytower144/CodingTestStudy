#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, p, d;
    cin >> n;

    vector<pair<int, int>> lectures;

    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        lectures.push_back({d, p});
    }
    sort(lectures.begin(), lectures.end());

    int answer = 0;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        pq.push(-lectures[i].second);

        if (pq.size() > lectures[i].first)
            pq.pop();
    }
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    cout << -answer;
    return 0;
}