#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string l, r;
    cin >> l >> r;
    
    int lSize = l.size();
    int rSize = r.size();
    if (lSize < rSize)
        l = string(rSize - lSize, '0') + l;
    else
        r = string(lSize - rSize, '0') + r;
    
    int size = min(lSize, rSize); 
    int eightCount = 0;

    for (int i = 0; i < size; i++) {
        if (l[i] == '8' && r[i] == '8')
            eightCount++;
        else if (l[i] == r[i])
            continue;
        else break;
    }
    cout << eightCount;
    return 0;
}
