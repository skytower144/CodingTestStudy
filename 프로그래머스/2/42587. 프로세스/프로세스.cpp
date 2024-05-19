#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();

    queue<int> q;
    int maxPriority = -1;
    
    for (int i = 0; i < n; i++)
        q.push(priorities[i]);
    
    vector<int> order = priorities;
    sort(order.begin(), order.end());
    maxPriority = order.back();
    
    while (!q.empty()) {
        int popped = q.front();
        q.pop();

        answer++;
        location--;
        
        if (popped < maxPriority) {
            q.push(popped);
            answer--;
            
            if (location == -1)
                location = n - 1 - answer;
        }
        else {
            order.pop_back();
            if (!order.empty())
                maxPriority = order.back();

            if (location == -1)
                return answer;
        }
    }
    return 0;
}