#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    double d, h, w;
    cin >> d >> h >> w;

    double x;
    x = d / sqrt(h * h + w * w);

    int height = floor(h * x);
    int width = floor(w * x);

    cout << height << " " << width;
    return 0;
}