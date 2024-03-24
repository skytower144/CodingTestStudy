#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const double PI = 3.141592;

    int d1, d2;
    cin >> d1 >> d2;

    double ab = 2.0 * d2 * PI;
    double answer = 2.0 * d1 + ab;

    cout << fixed;
    cout.precision(6);

    cout << answer;
    return 0;
}