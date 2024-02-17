#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int m, digit;
        char testType, character;
        cin >> m >> testType;

        switch (testType) {
            case 'C':
                for (int i = 0; i < m; i++) {
                    cin >> character;
                    cout << character - 'A' + 1 << " ";
                }
                break;
            
            case 'N':
                for (int i = 0; i < m; i++) {
                    cin >> digit;
                    cout << (char)('A' + digit - 1) << " ";
                }
                break;
            
            default:
                break;
        }
        cout << '\n';
    }
    return 0;
}
