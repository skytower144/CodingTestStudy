#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num) {
    int answer = 0, numSize = num.size();
    
    for (int i = 0; i < numSize - 2; i++) {
        for (int j = i + 1; j < numSize - 1; j++) {
            for (int k = j + 1; k < numSize; k++) {
                if (num[i] + num[j] + num[k] == 0) answer++;
            }
        }
    }
    return answer;
}