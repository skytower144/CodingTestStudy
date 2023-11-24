#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int answer = 0;
    int n;

    cin >> n;
    vector<int> A(n, 0);
    vector<int> B(n, 0);

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater());

    for (int i = 0; i < n; i++) answer += A[i] * B[i];
    cout << answer;
    return 0;
}