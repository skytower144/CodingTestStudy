#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    while (true) {
        vector<int> sides(3, 0);

        for (int i = 0; i < 3; i++)
            cin >> sides[i];

        if (sides[0] + sides[1] + sides[2] == 0)
            break;

        sort(sides.begin(), sides.end());

        if (sides[0] + sides[1] <= sides[2]) {
            cout << "Invalid" << '\n';
            continue;
        }
        int count = 0;
        if (sides[0] == sides[1]) count++;
        if (sides[1] == sides[2]) count++;
        if (sides[0] == sides[2]) count++;

        switch (count) {
            case 0:
                cout << "Scalene";
                break;
            
            case 1:
                cout << "Isosceles";
                break;

            default:
                cout << "Equilateral";
                break;
        }
        cout << '\n';
    }
    return 0;
}