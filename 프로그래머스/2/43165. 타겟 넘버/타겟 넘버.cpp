#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(int start, int sum, int target, vector<int>& numbers) {
    if (start == numbers.size()) {
        if (sum == target)
            answer++;
        return;
    }
    for (int i = start; i < numbers.size(); i++) {
        sum += numbers[i];
        DFS(i + 1, sum, target, numbers);
        sum -= numbers[i];

        sum -= numbers[i];
        DFS(i + 1, sum, target, numbers);
        sum += numbers[i];
        
        break;
    }
}

int solution(vector<int> numbers, int target) {
    DFS(0, 0, target, numbers);
    return answer;
}