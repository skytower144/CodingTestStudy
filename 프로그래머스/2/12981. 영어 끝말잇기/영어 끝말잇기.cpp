#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    unordered_map<string, int> wordDict;
    char lastChar = words[0][0];
    int turns = 1;
    int person = 0;
    
    for (const auto& word : words) {
        if (wordDict.count(word) || lastChar != word[0]) {
            answer = {person + 1, turns};
            break;
        }
        lastChar = word.back();
        wordDict[word]++;
        person++;
        
        if (person == n) {
            person = 0;
            turns++;
        }
    }
    return answer;
}