#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> kids(n, 0);
    vector<int> diff;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        cin >> kids[i];

        if (i > 0)
            diff.push_back(kids[i] - kids[i - 1]);
    }
    sort(diff.begin(), diff.end());

    // 막대기를 놓을 수 있는 공간 : n - 1
    // 놓을 수 있는 막대기 수 : k - 1
    // (n - 1) - (k - 1) = n - 1 - k + 1 = n - k

    for (int i = 0; i < (n - 1) - (k - 1); i++)
        answer += diff[i];
       
    cout << answer;
    return 0;
}
/*
막대기를 어디에 놓을 것인가

5 3 
1 4 5 7 8

 3 1 2 1
 * * * *
 |   |
*/