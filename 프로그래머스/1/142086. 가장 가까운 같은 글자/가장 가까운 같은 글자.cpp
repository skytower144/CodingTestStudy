#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.size(), -1);
    map<char, int> posMap;
    
    for (int i = 0; i < s.size(); i++) {
        if (!posMap.count(s[i]))
            posMap[s[i]] = i;
        else {
            answer[i] = i - posMap[s[i]];
            posMap[s[i]] = i;
        }
    }
    return answer;
}