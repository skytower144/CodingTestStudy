#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> countMap;
    int count = 0;
    
    for (auto key : keymap) {
        for (int i = 0; i < key.size(); i++) {
            if (!countMap.count(key[i]) || i + 1 < countMap[key[i]])
                countMap[key[i]] = i + 1;
        }
    }
    for (auto target : targets) {
        count = 0;
        for (auto c : target) {
            if (countMap.count(c))
                count += countMap[c];
            else {
                count = -1;
                break;
            }
        }
        answer.push_back(count);
    }
    return answer;
}