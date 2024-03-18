#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // https://www.acmicpc.net/blog/view/27
    // 가우스의 면적 공식
    
    ios::sync_with_stdio(0), cin.tie(0);

    pair<int, int> dots[3];
    int x, y;
    
    for (int i = 0; i < 3; i++) {
        cin >> x >> y;
        dots[i] = {x, y};
    }
    int area = (
        dots[0].first * dots[1].second +
        dots[1].first * dots[2].second +
        dots[2].first * dots[0].second
    ) - (
        dots[1].first * dots[0].second +
        dots[2].first * dots[1].second +
        dots[0].first * dots[2].second
    );
    if (area > 0)
        cout << 1;
    else if (area < 0)
        cout << -1;
    else
        cout << 0;
    return 0;
}