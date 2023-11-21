#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> rankMap;
    map<int, string> nameMap;
    string wentPast;
    
    for (int i = 0; i < players.size(); i++) {
        rankMap[players[i]] = i;
        nameMap[i] = players[i];
    }
    for (const auto call : callings) {
        rankMap[call]--;
        wentPast = nameMap[rankMap[call]];
        rankMap[wentPast]++;
        
        nameMap[rankMap[call]] = call;
        nameMap[rankMap[wentPast]] = wentPast;
    }
    for (auto [k, v] : nameMap) answer.push_back(v);
    return answer;
}