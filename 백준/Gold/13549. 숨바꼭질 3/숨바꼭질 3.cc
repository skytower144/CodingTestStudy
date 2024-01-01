#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> distance(100001, INT_MAX);
    priority_queue<pair<int, int>> pq;
    distance[n] = 0;
    pq.push({0, n});

    while (!pq.empty()) {
        int distanceSum = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (distanceSum > distance[pos]) 
            continue;
        
        int dx[] = {pos - 1, pos + 1, pos * 2};
        int dy[] = {1, 1, 0};

        for (int i = 0; i < 3; i++) {
            int nx = dx[i];
            int nextDistance = distanceSum + dy[i];

            if (nx < 0 || nx > 100000) continue;

            if (nextDistance < distance[nx]) {
                distance[nx] = nextDistance;
                pq.push({-nextDistance, nx});
            }
        }
    }
    cout << distance[k];
    return 0;
}