#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int height;
    int highest;
    int killStreak = 0;
    int maxKills = 0;

    for (int i = 0; i < n; i++) {
        cin >> height;
        if (i == 0) {
            highest = height;
            continue;
        }
        if (highest > height)
            killStreak++;
        else {
            killStreak = 0;
            highest = height;
        }
        maxKills = max(maxKills, killStreak);
    }
    cout << maxKills;    
    return 0;
}