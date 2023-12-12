#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    vector<int> levels(n, 0);
    for (int i = 0; i < n; i++) cin >> levels[i];

    int lastPoint = levels[n - 1] - 1;
    int answer = 0;

    for (int i = n - 2; i >= 0; i--) {
        while (levels[i] < lastPoint) lastPoint--;
        answer += levels[i] - lastPoint;
        lastPoint--;
    }
    cout << answer;
    return 0;
}