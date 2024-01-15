#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string name;
    map<string, int> notHeard;
    map<string, int> notSeen;
    vector<string> notHeardOrSeen;

    for (int i = 0; i < n; i++) {
        cin >> name;
        notHeard[name]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> name;
        notSeen[name]++;
    }
    for (const auto& [name, count] : notHeard) {
        if (notSeen.count(name))
            notHeardOrSeen.push_back(name);
    }
    sort(notHeardOrSeen.begin(), notHeardOrSeen.end());

    cout << notHeardOrSeen.size() << '\n';
    for (const auto& currentName : notHeardOrSeen)
        cout << currentName << '\n';
    
    return 0;
}