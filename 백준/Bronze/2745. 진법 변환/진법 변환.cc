#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string n;
    int b;

    cin >> n >> b;
    int addup = 0;
    int nSize = n.size();

    for (int i = 0; i < nSize; i++) {
        int digit;

        if (n[i] >= '0' && n[i] <= '9')
            digit = n[i] - '0';
        else
            digit = n[i] - 'A' + 10;
        
        addup += digit * pow(b, nSize - 1 - i);
    }
    cout << addup;
    return 0;
}