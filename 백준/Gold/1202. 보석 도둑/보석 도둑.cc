#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    long long answer = 0;
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> gems(n);
    vector<int> limits(k, 0);
    priority_queue<int> stored;

    for (int i = 0; i < n; i++)
        cin >> gems[i].first >> gems[i].second;
    
    for (int i = 0; i < k; i++)
        cin >> limits[i];

    sort(gems.begin(), gems.end());
    sort(limits.begin(), limits.end());

    int idx = 0;
    for (int i = 0; i < k; i++) {
        while (idx < n && limits[i] >= gems[idx].first) {
            stored.push(gems[idx].second);
            idx++;
        }
        if (!stored.empty()) {
            answer += stored.top();
            stored.pop();
        }
    }
    cout << answer;
    return 0;
}