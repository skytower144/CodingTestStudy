#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tenDigitSum = 91;
    int a, b, c;

    cin >> a >> b >> c;
    int answer = tenDigitSum + a * 1 + b * 3 + c * 1;

    cout << "The 1-3-sum is " << answer;
    return 0;
}