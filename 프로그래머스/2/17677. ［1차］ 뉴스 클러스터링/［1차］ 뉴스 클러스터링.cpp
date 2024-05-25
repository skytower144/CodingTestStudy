#include <string>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

bool CheckIgnore(string& word) {
    for (const auto& c : word) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
            return true;
    }
    return false;
}
void ToLower(string& word) {
    for (auto& c : word) {
        if (c >= 'A' && c <= 'Z')
            c = char(c + 'a' - 'A');
    }
}
void CreateComb(string& inputString, vector<string>& comb) {
    string temp;
    for (int i = 0; i < inputString.size() - 1; i++) {
        temp = string(1, inputString[i]) + inputString[i + 1];
        
        if (CheckIgnore(temp))
            continue;
        
        ToLower(temp);
        comb.push_back(temp);
    }
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> comb1, comb2;

    CreateComb(str1, comb1);
    CreateComb(str2, comb2);
    
    unordered_map<string, int> wordDict1, wordDict2;
    vector<int> visited2(comb2.size(), 0);
    int interCt = 0;
    int unionCt = 0;
    
    for (int i = 0; i < comb1.size(); i++) {
        wordDict1[comb1[i]]++;
        for (int j = 0; j < comb2.size(); j++) {
            if (visited2[j])
                continue;
            
            if (comb1[i] == comb2[j]) {
                interCt++;
                visited2[j] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < comb2.size(); i++)
        wordDict2[comb2[i]]++;
    
    for (auto [k, v] : wordDict2) {
        if (wordDict1.count(k))
            unionCt += max(wordDict1[k], v);
        else
            unionCt += v;
    }
    for (auto [k, v] : wordDict1) {
        if (wordDict2.count(k))
            continue;
        else
            unionCt += v;
    }
    answer = (interCt == 0 && unionCt == 0) ? 65536 : floor((double)interCt / unionCt * 65536);
    return answer;
}