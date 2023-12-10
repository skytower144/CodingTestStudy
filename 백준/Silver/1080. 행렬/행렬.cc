#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m;
    int answer = 0;
    cin >> n >> m;

    vector<vector<int>> A(n);
    vector<vector<int>> B(n);
    string line;

    for (int i = 0; i < n; i++) {
        cin >> line;
        for (auto l : line)
            A[i].push_back(l - '0');
    }
    for (int i = 0; i < n; i++) {
        cin >> line;
        for (auto l : line)
            B[i].push_back(l - '0');
    }
    for (int j = 0; j < m - 2; j++) {
        for (int i = 0; i < n - 2; i++) {
            bool flag = A[i][j] != B[i][j];

            for (int k = j; k < j + 3; k++) {
                for (int l = i; l < i + 3; l++) {
                    if (flag)
                        A[l][k] = !A[l][k];
                }
            }
            if (flag)
                answer++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << answer;
    return 0;
}
