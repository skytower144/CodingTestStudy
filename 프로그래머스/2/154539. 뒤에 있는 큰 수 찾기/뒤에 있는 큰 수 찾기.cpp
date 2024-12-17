#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    vector<pair<int, int>> stack;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        if (stack.empty() || stack.back().second >= numbers[i])
        {
            stack.push_back({i, numbers[i]});
            continue;
        }

        while (!stack.empty() && stack.back().second < numbers[i])
        {
            int index = stack.back().first;
            stack.pop_back();
            
            answer[index] = numbers[i];
        }
        
        stack.push_back({i, numbers[i]});
    }
    
    return answer;
}