#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack = {0};
    
    for (const auto food : ingredient) {
        if (stack.back() == 1 && food == 2) stack.back() = 12;
        else if (stack.back() == 12 && food == 3) stack.back() = 123;
        else if (stack.back() == 123 && food == 1) answer++, stack.pop_back();
        else stack.push_back(food);
    }
    return answer;
}