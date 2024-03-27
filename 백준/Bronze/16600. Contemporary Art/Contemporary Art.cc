#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    double area;
    cin >> area;

    double side = sqrt(area);
    double answer = side * 4;

    cout << fixed;
    cout.precision(6);

    cout << answer;
    return 0;
}