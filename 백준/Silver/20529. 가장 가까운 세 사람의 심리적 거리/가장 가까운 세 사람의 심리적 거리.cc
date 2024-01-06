#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;
vector<string> mbti;

int GetDistance(string a, string b, string c) {
    int distance = 0;

    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) distance++;
        if (b[i] != c[i]) distance++;
        if (a[i] != c[i]) distance++;
    }
    return distance;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        mbti = vector<string>(n);
        for (int i = 0; i < n; i++) cin >> mbti[i];
        
        if (n > 32) {
            cout << 0 << '\n';
            continue;
        }
        int minDistance = 100000;
        int totalDistance;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    totalDistance = GetDistance(mbti[i], mbti[j], mbti[k]);
                    minDistance = min(minDistance, totalDistance);
                }
            }
        }
        cout << minDistance << '\n';
    }
    return 0;
}