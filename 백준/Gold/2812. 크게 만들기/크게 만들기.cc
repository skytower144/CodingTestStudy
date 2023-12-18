#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    string num;
    string answer = "";
    cin >> n >> k >> num;

    for (int i = 0; i < n; i++) {
        while (!answer.empty() && k > 0 && answer.back() < num[i]) {
            answer.pop_back();
            k--;
        }
        answer += num[i];
    }
    while (k--) answer.pop_back();
    
    cout << answer;
    return 0;
}