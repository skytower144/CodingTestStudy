#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b;
    int answer = 1;
    
    cin >> a >> b;

    while (a < b) {
        if (b % 10 == 1) b /= 10;
        else if (b % 2 == 0) b /= 2;
        else break;
        answer++;
    }
    if (a != b) answer = -1;
    cout << answer;
    return 0;
}