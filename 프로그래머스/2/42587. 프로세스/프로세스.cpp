#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    
    vector<int> order = priorities;
    queue <int> q;
    
    sort(order.begin(), order.end());
    int maxPriority = order.back();
    
    for (int i = 0; i < n; i++)
        q.push(i);
    
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        
        if (priorities[idx] != maxPriority)
            q.push(idx);
        
        else {
            answer++;
            order.pop_back();
            
            if (idx == location)
                return answer;
            
            if (!order.empty())
                maxPriority = order.back();
        }
    }
    return 0;
}