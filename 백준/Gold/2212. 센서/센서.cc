#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> sensors(n, 0);
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) cin >> sensors[i];
    sort(sensors.begin(), sensors.end());

    int areaCount = 0;
    int areaStart = -1;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (areaStart == -1) areaStart = sensors[i];

        if (i == n - 1 || sensors[i] + 1 < sensors[i + 1]) {
            areaCount++;
            // cout << sensors[i] - areaStart << " ";
            // if (i != n - 1) cout << '[' << sensors[i + 1] - sensors[i] << ']' << " ";

            if (i != n - 1) pq.push((sensors[i + 1] - sensors[i]) * -1);
            answer += sensors[i] - areaStart;
            areaStart = -1;
        }
    }
    if (areaCount >= k) {
        for (int i = 0; i < areaCount - k; i++) {
            answer += pq.top() * -1;
            pq.pop();
        }
    }
    else {
        for (int i = areaCount; i < k; i++)
            answer--;
    }
    cout << max(0, answer);
    return 0;
}
/*
1 3  667 9

3  678 10 12 1415  18 20 
  3   2  2  2    3   2
0   2   0 0   1     0  0

0   2    2     1     2


1 2 3 4 5

1 1 1 1 1

*/