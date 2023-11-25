#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, num, first, second, mergedSum;
    int answer = 0;
    cin >> n;

    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> num;
        q.push(num * -1);
    }

    int size = q.size() - 1;
    for (int i = 0; i < size; i++) {
        first = q.top() * -1;
        q.pop();
        second = q.top() * -1;
        q.pop();
        
        mergedSum = first + second;
        answer += mergedSum;
        q.push(mergedSum * -1);
    }
    cout << answer;
    return 0;
}