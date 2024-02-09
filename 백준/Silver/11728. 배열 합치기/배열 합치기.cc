#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> A(n, 0);
    vector<int> B(m, 0);

    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    for (int i = 0; i < m; i++)
        cin >> B[i];
    
    int aPos = 0, bPos = 0;
    vector<int> answer;

    while (aPos < n || bPos < m) {
        if (aPos >= n) {
            answer.push_back(B[bPos]);
            bPos++;
            continue;
        }
        else if (bPos >= m) {
            answer.push_back(A[aPos]);
            aPos++;
            continue;
        }
        if (A[aPos] < B[bPos]) {
            answer.push_back(A[aPos]);
            aPos++;
        }
        else {
            answer.push_back(B[bPos]);
            bPos++;
        }
    }
    for (const auto& a : answer)
        cout << a << " ";
    return 0;
}