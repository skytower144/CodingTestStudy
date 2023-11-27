#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long long answer = 0;
int num1, num2;

int BindNumbers(priority_queue<int>& q, bool isPositive) {
    int count = q.size();

    while (count > 1) {
        num1 = q.top(), q.pop();
        num2 = q.top(), q.pop();
        
        if (isPositive && (num1 == 1 || num2 == 1))
            answer += num1 + num2;
        else
            answer += num1 * num2;

        count -= 2;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, num;
    cin >> n;

    priority_queue<int> positives, negatives;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > 0) positives.push(num);
        else negatives.push(num * -1);
    }
    int posCount = BindNumbers(positives, true);
    int negCount = BindNumbers(negatives, false);

    int leftNums = posCount + negCount;
    if (leftNums == 1)
        answer += positives.empty() ? negatives.top() * -1 : positives.top();
    
    else if (leftNums == 2)
        answer += positives.top() + negatives.top() * -1;

    cout << answer;
    return 0;
}