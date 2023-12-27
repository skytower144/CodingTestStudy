#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    long long anger = 0;
    vector<int> expect(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> expect[i];
    }
    sort(expect.begin(), expect.end());
    for (int i = 1; i <= n; i++) {
        anger += abs(expect[i - 1] - i);
    }
    cout << anger;
    return 0;
}
/*
1 1 2 3 5
1 2 3 4 5

*/