#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> flagRelations, flaggedRecord;
    map<string, set<string>> flagRecord;
    string flagger = "", flagged = "";
    
    for (const auto r : report) {
        stringstream ss(r);
        ss >> flagger >> flagged;
        
        if (!flagRelations.count(r)) {
            flagRelations[r]++;
            flaggedRecord[flagged]++;
        }
        flagRecord[flagger].insert(flagged);
    }
    for (const auto id : id_list) {
        int notify = 0;
        
        for (const auto target : flagRecord[id]) if (flaggedRecord[target] >= k) notify++;
        answer.push_back(notify);
    }
    return answer;
}