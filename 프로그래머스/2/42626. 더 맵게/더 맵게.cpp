#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    
    for (int i = 0; i < scoville.size(); i++)
        pq.push(-scoville[i]);
    
    while (-pq.top() < K) {
        if (pq.size() == 1)
            return -1;
        
        int popped1 = -pq.top();
        pq.pop();
        
        int popped2 = -pq.top();
        pq.pop();
        
        int combined = popped1 + (popped2 * 2);
        pq.push(-combined);
        answer++;
    }
    return answer;
}