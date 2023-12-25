#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> heights(n, 0);
        deque<int> dq;
        int answer = -1;
        
        for (int i = 0; i < n; i++) cin >> heights[i];
        sort(heights.begin(), heights.end());

        dq.push_back(heights[n - 1]);
        for (int i = n - 3; i >= 0; i -= 2) {
            answer = max(answer, abs(dq.front() - heights[i]));
            dq.push_front(heights[i]);

            answer = max(answer, abs(dq.back() - heights[i + 1]));
            dq.push_back(heights[i + 1]);
        }
        if (n % 2 == 0)
            dq.push_front(heights[0]);
         
        answer = max(answer, abs(dq.back() - dq.front()));
        cout << answer << '\n';
    }
    return 0;
}
/*
10 10 11 11 12 12 13
=> 10 11 12 13 12 11 10 

1 3 5 6 8 9
=> 1 3 6 9 8 5
*/