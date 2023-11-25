#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;

    int zeros = 0;
    int ones = 0;

    char lastType = s[0];
    lastType == '0' ? zeros++ : ones++;

    for (int i = 1; i < s.size(); i++) {
        if (lastType != s[i]) {
            s[i] == '0' ? zeros++ : ones++;
            lastType = s[i];
        }
    }
    cout << min(zeros, ones);

    return 0;
}