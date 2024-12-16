#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> cards) {
    int answer = 1;
    
    vector<vector<int>> chains;
    vector<bool> visited(cards.size(), false);
    priority_queue<int> pq;
    
    for (int i = 0; i < cards.size(); i++)
    {
        int nextBox = i;
        int count = 0;
        vector<int> chain;
        
        while (!visited[nextBox])
        {
            visited[nextBox] = true;
            chain.push_back(nextBox + 1);
            nextBox = cards[nextBox] - 1;
            
            count++;
        }
        
        chains.push_back(chain);
        pq.push(count);
    }
    
    int ct = 2;
    
    while (ct--)
    {
        answer *= pq.top();
        pq.pop();
    }
    
    return answer;
}