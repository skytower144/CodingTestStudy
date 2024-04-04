#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://jaimemin.tistory.com/674

vector<bool> visited;
vector<bool> isDetermined;
vector<int> picks;
int grouped = 0;
int t, n;

void CheckGroup(int start) {
    visited[start] = true;
    int next = picks[start];

    if (!visited[next])
        CheckGroup(next);
    
    else if (visited[next] && !isDetermined[next]) {
        for (int i = next; i != start; i = picks[i])
            grouped++;
        grouped++;
    }
    isDetermined[start] = true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;
        picks = vector<int>(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> picks[i];
        
        visited = vector<bool>(n + 1);
        isDetermined = vector<bool>(n + 1);
        grouped = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                CheckGroup(i);
        }
        cout << (n - grouped) << '\n';
    }
    return 0;
}