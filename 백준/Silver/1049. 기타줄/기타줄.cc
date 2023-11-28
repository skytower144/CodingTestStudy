#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<int> packagePrice(m, 0);
    vector<int> singlePrice(m, 0);
    int cheapestFullSet = 1001, cheapestLeftSet = 1001;
    int cheaperFullSet, cheaperLeftSet;

    for (int i = 0; i < m; i++) {
        cin >> packagePrice[i] >> singlePrice[i];
        cheaperFullSet = min(packagePrice[i], singlePrice[i] * 6);
        cheaperLeftSet = min(packagePrice[i], singlePrice[i] * (n % 6));

        if (cheapestFullSet > cheaperFullSet )
            cheapestFullSet = cheaperFullSet;
        
        if (cheapestLeftSet > cheaperLeftSet)
            cheapestLeftSet = cheaperLeftSet;
    }
    cout << (n / 6) * cheapestFullSet + cheapestLeftSet;
    return 0;
}