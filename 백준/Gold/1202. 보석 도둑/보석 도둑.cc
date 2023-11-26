#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    long long answer = 0;
    int n, k, weight, value, limit;
    cin >> n >> k;

    priority_queue<pair<int, int>> gems;
    priority_queue<int> weightLimits;
    priority_queue<int> stored;

    for (int i = 0; i < n; i++) {
        cin >> weight >> value;
        gems.push(pair<int, int>(weight * -1, value));
    }
    for (int i = 0; i < k; i++) {
        cin >> weight;
        weightLimits.push(weight * -1);
    }

    int idx = 0;
    for (int i = 0; i < k; i++) {
        limit = weightLimits.top() * -1;
        
        while (idx < n && limit >= gems.top().first * -1) {
            stored.push(gems.top().second);
            gems.pop();
            idx++;
        }
        if (!stored.empty()) {
            answer += stored.top();
            stored.pop();
        }
        weightLimits.pop();
    }
    cout << answer;
    return 0;
}