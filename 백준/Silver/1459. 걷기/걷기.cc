#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    /* https://jaewoo2233.tistory.com/36
    
    distance1 : 대각선이 아예 손해인 경우 (w < s && 2 * w < s)
    distance2 : 대각선이 아예 이득인 경우 (w > s)
    distance3 : 대각선이 1블록에 비해 손해지만 2블록보다는 이득일 경우 
    */
    ios::sync_with_stdio(0), cin.tie(0);
    
    long long x, y, w, s;
    cin >> x >> y >> w >> s;

    long long distance1, distance2, distance3;

    distance1 = (x + y) * w;

    if ((x + y) % 2 == 0)
        distance2 = max(x, y) * s;
    else
        distance2 = (max(x, y) - 1) * s + w;
    
    distance3 = min(x, y) * s + abs(x - y) * w;

    cout << min(distance1, min(distance2, distance3));
    return 0;
}