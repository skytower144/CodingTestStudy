#include <string>
#include <vector>
#include <map>

using namespace std;

bool IsRepeatBabble(vector<string> record) {
    for (int i = 1; i < record.size(); i++)
        if (record[i] == record[i - 1]) return true;
    return false;
}

int solution(vector<string> babbling) {
    int answer = 0, totalLength = 0;
    bool isBabble = true;
    string temp = "";
    vector<string> record;
    
    map<string, int> babbleMap = {
        {"aya", 1}, {"ye", 1}, {"woo", 1}, {"ma", 1}
    };
    
    for (const auto babble : babbling) {
        isBabble = true;
        totalLength = 0;
        temp = "";
        record = {};
        
        for (const auto b : babble) {
            temp += b;
            if (babbleMap.count(temp)) {
                totalLength += temp.size();
                record.push_back(temp);
                temp = "";
            }
        }
        if (totalLength == babble.size() && !IsRepeatBabble(record)) answer++;
    }
    return answer;
}