#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int index = 1;
    int n0, n1, n2, n3, n4;

    while (true) {
        cin >> n0;
        if (n0 == 0) break;

        n1 = n0 * 3;
        bool isEven = n1 % 2 == 0;
        string typeName = isEven ? "even" : "odd";
        
        if (isEven)
            n2 = n1 / 2;
        else
            n2 = (n1 + 1) / 2;
        
        n3 = n2 * 3;
        n4 = n3 / 9;

        if (isEven)
            n0 = n4 * 2;
        else
            n0 = n4 * 2 + 1;
        
        cout << index << ". " << typeName << " " << n4 << '\n'; 
        index++;
    }
    return 0;
}