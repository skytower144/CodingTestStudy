#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int height;
    vector<int> mountains;
    vector<int> kills(n, 0);
    vector<bool> blocked(n, false);

    for (int i = 0; i < n; i++) {
        cin >> height;

        for (int j = 0; j < i; j++) {
            if (!blocked[j] && mountains[j] > height)
                kills[j]++;
            else
                blocked[j] = true;
        }
        mountains.push_back(height);
    }
    int maxKills = 0;
    for (int i = 0; i < n; i++)
        maxKills = max(maxKills, kills[i]);

    cout << maxKills;    
    return 0;
}