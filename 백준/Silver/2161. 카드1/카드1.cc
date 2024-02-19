#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    queue<int> cards;
    for (int i = 1; i <= n; i++)
        cards.push(i);
    
    int i = 0;
    while (!cards.empty()) {
        if (i % 2 == 0) {
            cout << cards.front() << " ";
            cards.pop();
        }
        else {
            int front = cards.front();
            cards.pop();
            cards.push(front);
        }
        i++;
    }
    return 0;
}