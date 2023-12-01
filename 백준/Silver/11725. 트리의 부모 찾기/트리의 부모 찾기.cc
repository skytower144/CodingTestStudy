#include <iostream>
#include <vector>

using namespace std;
#define MAX 100001

vector<int> parentList(MAX);
vector<vector<int>> tree(MAX);

void CreateTree(int parent) {
    int child;
    for (int i = 0; i < tree[parent].size(); i++) {
        child = tree[parent][i];
        if (parentList[child] == 0) {
            parentList[child] = parent;
            CreateTree(child);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, num1, num2;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> num1 >> num2;
        tree[num1].push_back(num2);
        tree[num2].push_back(num1);
    }
    parentList[1] = -1;
    CreateTree(1);

    for (int i = 2; i <= n; i++)
        cout << parentList[i] << "\n";
}