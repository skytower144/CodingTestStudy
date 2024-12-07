#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int> q;
    int sum = 0;
    
    for (int i = 0; i < enemy.size(); i++)
    {
        q.push(enemy[i]);
        sum += enemy[i];
        
        while (sum > n && k > 0)
        {
            int popped = q.top();
            q.pop();
            
            sum -= popped;
            k--;
        }
 
        if (k == 0 && sum > n)
        {
            answer = i;
            break;
        }
        
        answer = i + 1;
    }
    
    return answer;
}
