#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int w, h;
    cin >> w >> h;

    double answer = w * h / 2.0;

    cout << fixed;
    cout.precision(1);

    cout << answer;
    return 0;
}