#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> pq;
    int dasom, votes;
    int bribed = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0)
            cin >> dasom;
        else {
            cin >> votes;
            pq.push(votes);
        }
    }
    while (!pq.empty() && dasom <= pq.top()) {
        pq.push(pq.top() - 1);
        pq.pop();
        bribed++;
        dasom++;
    }
    cout << bribed;
    return 0;
}