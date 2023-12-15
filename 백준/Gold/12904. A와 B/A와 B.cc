#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, t;
    cin >> s >> t;

    int tIndex = t.size() - 1;
    if (s.size() > t.size()) {
        cout << 0;
        return 0;
    }
    while (tIndex >= 1) {
        if (s == t) break;

        if (t[tIndex] == 'A')
            t.pop_back();
        
        else if (t[tIndex] == 'B') {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        else break;
        tIndex--;
    }
    s == t ? cout << 1 : cout << 0;
    return 0;
}