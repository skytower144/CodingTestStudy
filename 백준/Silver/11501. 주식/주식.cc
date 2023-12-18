#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int T, n;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> n;
        vector<int> prices(n);
        vector<pair<int, int>> priceInfo(n);
        int currentIndex = 0;
        long long profit = 0;

        for (int i = 0; i < n; i++) {
            cin >> prices[i];
            priceInfo[i].first = prices[i];
            priceInfo[i].second = i;
        }
        sort(priceInfo.begin(), priceInfo.end());

        while (!priceInfo.empty() || currentIndex < n) {
            int maxPrice = priceInfo.back().first;
            int maxIndex = priceInfo.back().second;
            priceInfo.pop_back();

            if (currentIndex > maxIndex) continue;

            for (int i = currentIndex; i < maxIndex; i++)
                profit += maxPrice - prices[i];
            
            currentIndex = maxIndex + 1;
        }
        cout << profit << '\n';
    }

    return 0;
}