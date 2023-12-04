#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int answer = 0;
    int n;
    cin >> n;

    while (n > 1) {
        n % 5 ? n -= 2 : n -= 5;
        answer++;
    }
    if (n == 1) answer = -1;
    cout << answer;
    return 0;
}