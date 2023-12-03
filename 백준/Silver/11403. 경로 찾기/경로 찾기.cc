#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int grid[100][100];
unordered_map<int, vector<int>> linkedMap;

int FindPath(int i, int j) {
    int visited[100] = {0,};
    int num;

    queue<int> q;
    q.push(i);
    visited[i] = true;
    
    while (!q.empty()) {
        num = q.front();
        q.pop();

        for (auto linkedNum : linkedMap[num]) {
            if (linkedNum == j)
                return true;

            if (!visited[linkedNum]) {
                q.push(linkedNum);
                visited[linkedNum] = true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j])
                linkedMap[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << FindPath(i, j) << " ";
        cout << "\n";
    }
}