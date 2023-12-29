#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> tips(n, 0);
    for (int i = 0; i < n; i++) cin >> tips[i];
    sort(tips.begin(), tips.end(), greater());

    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += max(0, tips[i] - i); 
    }    
    cout << answer;
    return 0;
}