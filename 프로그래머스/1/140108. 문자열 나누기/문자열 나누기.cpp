#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1, size = s.size();
    char firstChar = s[0];
    vector<int> counter(2, 0);
    
    for (int i = 0; i < size; i++) {
        firstChar == s[i] ? counter[0]++ : counter[1]++;
        if (counter[0] == counter[1] && i + 1 < size) {
            firstChar = s[i + 1];
            answer++;
        }
    }
    return answer;
}