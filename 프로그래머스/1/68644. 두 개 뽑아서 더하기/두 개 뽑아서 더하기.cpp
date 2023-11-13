#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int, int> possibleNums;
    int result = 0;
    
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            result = numbers[i] + numbers[j];
            if (!possibleNums.count(result))
                possibleNums[result] = 1;
        }
    }
    for (const auto kv : possibleNums) answer.push_back(kv.first);
    return answer;
}