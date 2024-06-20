#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> parsedRecord;
    unordered_map<string, string> idMap;
    
    for (string line : record) {
        vector<string> userInfo;
        stringstream ss(line);
        string token;
        
        while (ss >> token)
            userInfo.push_back(token);
        
        if (userInfo[0] == "Enter" || userInfo[0] == "Change")
            idMap[userInfo[1]] = userInfo[2];
        
        parsedRecord.push_back({userInfo[0], userInfo[1]});
    }
    for (const auto& [act, id] : parsedRecord) {
        string sentence;
        
        if (act == "Enter")
            sentence = idMap[id] + "님이 들어왔습니다.";

        if (act == "Leave")
            sentence = idMap[id] + "님이 나갔습니다.";
        
        if (!sentence.empty())
            answer.push_back(sentence);
    }
    return answer;
}