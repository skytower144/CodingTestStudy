#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<long long> cards(n, 0);
    for (int i = 0; i < n; i++) cin >> cards[i];

    for (int i = 0; i < m; i++) {
        sort(cards.begin(), cards.end());
        long long result = cards[0] + cards[1];
        cards[0] = cards[1] = result;
    }
    long long answer = 0;
    for (int i = 0; i < n; i++)
        answer += cards[i];
    
    cout << answer;
    return 0;
}