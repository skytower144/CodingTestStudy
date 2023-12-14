#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m, num;
    cin >> n >> m;

    priority_queue<long long> pq;
    long long card1, card2, result;

    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num * -1);
    }
    for (int i = 0; i < m; i++) {
        card1 = pq.top() * -1, pq.pop();
        card2 = pq.top() * -1, pq.pop();
        result = card1 + card2;
        pq.push(result * -1);
        pq.push(result * -1);
    }
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += pq.top() * -1;
        pq.pop();
    }
    cout << answer;
    return 0;
}