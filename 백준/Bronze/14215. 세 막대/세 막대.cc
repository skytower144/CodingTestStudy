#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    vector<int> sides(3);
    for (int i = 0; i < 3; i++)
        cin >> sides[i];
    
    sort(sides.begin(), sides.end());
    int answer = sides[0] + sides[1] + sides[2];
    
    if (sides[0] + sides[1] <= sides[2])
        answer = 2 *(sides[0] + sides[1]) - 1;
    
    cout << answer;
    return 0;
}