#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

// https://ongveloper.tistory.com/295

int treeSize;
vector<int> tree;

void UpdateTree(int startIndex, int endIndex) {
    if (startIndex > endIndex)
        return;
    
    if (startIndex == endIndex) {
        cout << tree[startIndex] << '\n';
        return;
    }
    int left = startIndex + 1;
    int right = left;

    for (int i = left; i <= endIndex; i++) {
        if (tree[startIndex] < tree[i]) {
            right = i;
            break;
        }
    }
    UpdateTree(left, right - 1);
    UpdateTree(right, endIndex);
    cout << tree[startIndex] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;

    while (cin >> n)
        tree.push_back(n);
    
    UpdateTree(0, tree.size() - 1);
    return 0;
}