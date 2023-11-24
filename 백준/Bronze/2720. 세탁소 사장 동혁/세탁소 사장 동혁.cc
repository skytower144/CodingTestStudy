#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    int change, coin;

    cin >> n;
    vector<int> changes(n, 0);
    vector<int> answer(4, 0);
    vector<int> coinValue = {25, 10, 5, 1};

    for (int i = 0; i < n; i++) cin >> changes[i];
    
    for (int i = 0; i < n; i++) {
        change = changes[i];
        answer = vector<int>(4, 0);

        for (int j = 0; j < 4; j++) {
            coin = coinValue[j];
            if (coin > change) continue;
            
            answer[j] = change / coin;
            change -= answer[j] * coin;
        }
        cout << answer[0] << " " << answer[1] << " " << answer[2] << " " << answer[3] << endl;
    }
    return 0;
}