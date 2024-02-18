#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int answer = 0;
    int n, deadline, ramen;

    vector<pair<int, int>> v;
    priority_queue<int> pq;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> deadline >> ramen;
        v.push_back({deadline, ramen});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        pq.push(-v[i].second);

        if (pq.size() > v[i].first)
            pq.pop();
    }
    while (!pq.empty()) {
        answer += -pq.top();
        pq.pop();
    }
    cout << answer;
    return 0;
}