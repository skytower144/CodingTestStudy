#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

bool FindCard(vector<int>& cards, int target) {
    int startIdx = 0;
    int endIdx = n - 1;
    int midIdx;

    while (startIdx <= endIdx) {
        midIdx = (startIdx + endIdx) / 2;

        if (cards[midIdx] == target)
            return true;
        
        else if (cards[midIdx] < target)
            startIdx = midIdx + 1;
        
        else
            endIdx = midIdx - 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    vector<int> cards(n, 0);
    for (int i = 0; i < n; i++) cin >> cards[i];

    cin >> m;
    vector<int> targets(m, 0);
    for (int i = 0; i < m; i++) cin >> targets[i];

    sort(cards.begin(), cards.end());

    for (const auto target : targets)
        cout << FindCard(cards, target) << " ";
    
    return 0;
}