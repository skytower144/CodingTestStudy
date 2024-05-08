#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    unordered_map<string, int> wordDict;
    wordDict[words[0]]++;
    
    for (int i = 1; i < words.size(); i++) {
        if (wordDict[words[i]] || words[i][0] != words[i - 1].back()) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        wordDict[words[i]]++;
    }
    return answer;
}