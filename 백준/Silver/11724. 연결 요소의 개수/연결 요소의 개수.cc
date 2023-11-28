#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int answer = 0;
    int n, m, num1, num2, currentNum;
    cin >> n >> m;

    unordered_map<int, vector<int>> nums;
    int visited[1001] = {0,};
    queue<int> q;

    for (int i = 0; i < m; i++) {
        cin >> num1 >> num2;
        nums[num1].push_back(num2);
        nums[num2].push_back(num1);
    }

    for (auto [k, v] : nums) {
        if (!visited[k]) {
            q.push(k);
            visited[k] = 1;
            answer++;
        }
        while(!q.empty()) {
            currentNum = q.front();
            q.pop();

            for (auto linkedNum : nums[currentNum]) {
                if (!visited[linkedNum]) {
                    q.push(linkedNum);
                    visited[linkedNum] = 1;
                }
            }
        }
    }
    if (nums.size() != n) {
        answer += n - nums.size();
    }
    cout << answer;
    return 0;
}