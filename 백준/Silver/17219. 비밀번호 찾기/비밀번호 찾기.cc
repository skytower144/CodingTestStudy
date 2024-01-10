#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string website, password;
    unordered_map<string, string> passwordMap;
    
    for (int i = 0; i < n; i++) {
        cin >> website >> password;
        passwordMap[website] = password;
    }
    for (int i = 0; i < m; i++) {
        cin >> website;
        cout << passwordMap[website] << '\n';
    }
    return 0;
}