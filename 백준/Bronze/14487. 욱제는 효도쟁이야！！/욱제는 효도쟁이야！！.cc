#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int maxDist = -1;
    int totalDist = 0;
    vector<int> islands(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> islands[i];
        totalDist += islands[i];
        maxDist = max(maxDist, islands[i]);
    }
    cout << totalDist - maxDist;
    return 0;
}