#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <iostream>

// https://tech.kakao.com/posts/420

using namespace std;

unordered_map<string, vector<int>> infoMap;

void InitComb(int comb, int score, vector<string>& component)
{
    string key = "";
    for (int i = 0; i < 4; i++)
    {
        if (comb & (1 << i))
            key += component[i];
        else
            key += "-";
    }
    
    infoMap[key].push_back(score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
   
    string lang, pos, career, food, _;
    int score;
    
    for (int i = 0; i < info.size(); i++)
    {
        stringstream ss(info[i]);
        ss >> lang >> pos >> career >> food >> score;
        
        vector<string> component = {lang, pos, career, food};
        
        for (int i = 0; i < 16; i++)
            InitComb(i, score, component);
    }
    
    for (auto& [key, scores] : infoMap)
        sort(scores.begin(), scores.end());
    
    for (const auto& line : query)
    {
        stringstream ss(line);
        
        ss >> lang >> _ >> pos >> _ >> career >> _ >> food >> score;
        vector<string> queryInfo = { lang, pos, career, food };

        string key = lang + pos + career + food;
        
        int count = infoMap[key].size() - (lower_bound(infoMap[key].begin(), infoMap[key].end(), score) - infoMap[key].begin());
        answer.push_back(count);
    }
    
    return answer;
}