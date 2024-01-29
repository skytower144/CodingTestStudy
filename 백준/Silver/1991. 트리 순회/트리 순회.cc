#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<char, pair<char, char>> nodeMap;

void Preorder(char current) {
    if (current == '.')
        return;
    
    cout << current;
    Preorder(nodeMap[current].first);
    Preorder(nodeMap[current].second);
}

void Inorder(char current) {
    if (current == '.')
        return;
    
    Inorder(nodeMap[current].first);
    cout << current;
    Inorder(nodeMap[current].second);
}
void Postorder(char current) {
    if (current == '.')
        return;
    
    Postorder(nodeMap[current].first);
    Postorder(nodeMap[current].second);
    cout << current;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    char parent, left, right;

    for (int i = 0; i < n; i++) {
        cin >> parent >> left >> right;
        nodeMap[parent] = {left, right};
    }
    Preorder('A');
    cout << '\n';

    Inorder('A');
    cout << '\n';

    Postorder('A');

    return 0;
}