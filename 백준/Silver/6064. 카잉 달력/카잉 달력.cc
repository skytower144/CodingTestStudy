#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t, M, N, x, y;
    cin >> t;

    while (t--) {
        cin >> M >> N >> x >> y;

        int limit = lcm(M, N);
        int answer = -1;

        while (x <= limit) {
            if (x % N == y || (x % N == 0 && y == N)) {
                // x % N == 0 이라는 것은 현재 y가 N값이라는 뜻
                answer = x;
                break;
            }
            x += M;
        }
        cout << answer << '\n';
    }
    return 0;
}
/*
M = 10, N = 12, x = 3, y = 9
Q. x만 알맞은 값이 나오려면 몇 번째 해가 되어야 하는지 생각해 보자.
https://www.acmicpc.net/board/view/21503

1:1     - 1
2:2     - 2
3:3     - 3 | y = 3 % 12

4:4     - 4
5:5     - 5
6:6     - 6
7:7     - 7
8:8     - 8
9:9     - 9
10:10   - 10
1:11    - 11
2:12    - 12
3:1     - 13 | y = 13 % 12

4:2     - 14
5:3     - 15
6:4     - 16
7:5     - 17
8:6     - 18
9:7     - 19
10:8    - 20
1:9     - 21
2:10    - 22
3:11    - 23 | y = 23 % 12

x를 고정시키고 y를 계속 변화시킬 때
만족하는 y가 있는지 찾아보면 되기 때문에 x += M
*/