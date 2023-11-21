#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> yearnMap;
    int yearnPoint;
    
    for (int i = 0; i < name.size(); i++)
        yearnMap[name[i]] = yearning[i];
    
    for (const auto p : photo) {
        yearnPoint = 0;
        for (const auto person : p) {
            if (yearnMap.count(person)) 
                yearnPoint += yearnMap[person];
        }
        answer.push_back(yearnPoint);
    }
    return answer;
}