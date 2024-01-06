#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;
vector<string> mbti;

int GetDistance(int idx1, int idx2) {
    string a = mbti[idx1];
    string b = mbti[idx2];
    int distance = 0;

    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i])
            distance++;
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

        for (int i = 0; i < n; i++)
            cin >> mbti[i];
        
        int minDistance = 100000;
        bool flag = false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int totalDistance;

                    if (mbti[i] == mbti[j] && mbti[j] == mbti[k])
                        totalDistance = 0;
                    else
                        totalDistance = GetDistance(i, j) + GetDistance(j, k) + GetDistance(i, k);
                    
                    minDistance = min(minDistance, totalDistance);
                    if (minDistance == 0) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        cout << minDistance << '\n';
    }
    return 0;
}