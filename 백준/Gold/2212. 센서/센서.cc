#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> sensors(n, 0);
    priority_queue<int> pq;
    int distance;
    int answer = 0;

    for (int i = 0; i < n; i++) cin >> sensors[i];
    sort(sensors.begin(), sensors.end());

    for (int i = 0; i < n - 1; i++) {
        distance = sensors[i + 1] - sensors[i];
        pq.push(distance * -1);
    }
    for (int i = 0; i < n - k; i++) {
        answer += pq.top() * -1;
        pq.pop();
    }
    cout << answer;
    return 0;
}