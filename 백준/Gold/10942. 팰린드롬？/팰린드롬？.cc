#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
vector<vector<int>> dp;

int IsPalindrome(int s, int e) {
    if (dp[s][e] != -1)
        return dp[s][e];
    
    if (numbers[s] == numbers[e] && e - s >= 2)
        dp[s][e] = IsPalindrome(s + 1, e - 1);
    else
        dp[s][e] = numbers[s] == numbers[e];
    
    return dp[s][e];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    numbers = vector<int>(n + 1, 0);
    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++)
        cin >> numbers[i];
    
    int m, s, e;
    cin >> m;

    while (m--) {
        cin >> s >> e;
        cout << IsPalindrome(s, e) << '\n';
    }
    return 0;
}