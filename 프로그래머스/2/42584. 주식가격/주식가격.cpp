#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> stack = {0};
    
    for (int i = prices.size() - 1; i >= 0; i--)
        answer.push_back(i);
    
    for (int i = 1; i < prices.size(); i++) {
        while (!stack.empty() && prices[stack.back()] > prices[i]) {
            int popped = stack.back();
            stack.pop_back();
            answer[popped] = i - popped;
        }
        stack.push_back(i);
    }
    return answer;
}