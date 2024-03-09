#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int start_x, start_y, end_x, end_y, n;
        cin >> start_x >> start_y >> end_x >> end_y >> n;

        int c_x, c_y, r;
        int startDistance, endDistance, radiusDistance;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            cin >> c_x >> c_y >> r;
            
            radiusDistance = pow(r, 2);
            startDistance = pow((start_x - c_x), 2) + pow((start_y - c_y), 2);
            endDistance = pow((end_x - c_x), 2) + pow((end_y - c_y), 2);

            int count = 0;
            if (startDistance <= radiusDistance)
                count++;
            
            if (endDistance <= radiusDistance)
                count++;
            
            if (count == 1)
                answer++;
        }
        cout << answer << '\n';
    }
    return 0;
}