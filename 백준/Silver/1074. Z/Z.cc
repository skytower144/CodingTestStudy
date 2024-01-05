#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, r, c;
int idx = 0;

void SearchZ(int n, int x, int y) {
    if (n == 0)
        return;
    
    int multiply = 0;
    int amount = pow(2, n - 1) / 2;
    
    if (r < y && c < x) {
        multiply = 0;
        y -= amount;
        x -= amount;
    }
    else if (r < y && c >= x) {
        multiply = 1;
        y -= amount;
        x += amount;
    }
    else if (r >= y && c < x) {
        multiply = 2;
        y += amount;
        x -= amount;
    }
    else if (r >= y && c >= x) {
        multiply = 3;
        y += amount;
        x += amount;
    }
    idx += pow(pow(2, n - 1), 2) * multiply;
    SearchZ(n - 1, x, y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> r >> c;
    int first = pow(2, n) / 2;
    SearchZ(n, first, first);
    
    cout << idx;
    return 0;
}