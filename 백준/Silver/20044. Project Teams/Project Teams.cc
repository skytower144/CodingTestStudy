#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> students(2 * n, 0);
    for (int i = 0; i < 2 * n; i++)
        cin >> students[i];

    sort(students.begin(), students.end());
    int answer = INT_MAX;

    for (int i = 0; i < n; i++) {
        answer = min(answer, students[i] + students[2 * n - 1 - i]);
    }
    cout << answer;
    return 0;
}