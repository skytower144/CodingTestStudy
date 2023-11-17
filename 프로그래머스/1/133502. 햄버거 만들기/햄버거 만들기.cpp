#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0, size = 0;
    vector<int> stack;
    
    for (const auto food : ingredient) {
        stack.push_back(food);
        size = stack.size();
        
        if (size >= 4 && stack[size - 4] == 1 && stack[size - 3] == 2 && stack[size - 2] == 3 && stack[size - 1] == 1) {
            answer++;
            for (int i = 0; i < 4; i++) stack.pop_back();
        }
    }
    return answer;
}