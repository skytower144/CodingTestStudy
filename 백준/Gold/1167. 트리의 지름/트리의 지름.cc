#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> visited;
int farthestNode;
int answer = -1;

void DFS(int currentNode, int distanceSum) {
    visited[currentNode] = 1;
    if (answer < distanceSum) {
        answer = distanceSum;
        farthestNode = currentNode;
    }
    for (const auto& [child, d] : graph[currentNode]) {
        if (!visited[child])
            DFS(child, distanceSum + d);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, a, b, c;
    cin >> n;

    graph = vector<vector<pair<int, int>>>(n + 1);
    visited = vector<int>(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a;
        while (true) {
            cin >> b;
            if (b == -1) break;
            cin >> c;

            graph[a].push_back({b, c});
        }
    }
    DFS(1, 0);

    answer = -1;
    visited = vector<int>(n + 1, 0);
    DFS(farthestNode, 0);

    cout << answer;
    return 0;
}