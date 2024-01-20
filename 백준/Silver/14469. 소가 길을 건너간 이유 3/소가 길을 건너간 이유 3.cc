#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<pair<int, int>> pq;
    int arrival, duration;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        cin >> arrival >> duration;
        pq.push({-arrival, duration});       
    }
    for (int i = 0; i < n; i++) {
        arrival = -pq.top().first;
        duration = pq.top().second;
        pq.pop();

        if (currentTime < arrival)
            currentTime = arrival;
        
        currentTime += duration;
    }
    cout << currentTime;
    return 0;
}