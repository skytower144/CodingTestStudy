#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    const int MONTH = 28;
    const int YEAR = 12 * MONTH;
    vector<int> answer;
    map<char, int> termMap;
    
    int today_y = stoi(today.substr(0, 4));
    int today_m = stoi(today.substr(5, 2));
    int today_d = stoi(today.substr(8, 2));
    int today_total = today_y * YEAR + today_m * MONTH + today_d;
    
    for (auto term : terms)
        termMap[term[0]] = stoi(term.substr(2, 3)) * MONTH;
    
    for (int i = 1; i <= privacies.size(); i++) {
        string privacy = privacies[i - 1];
        
        int start_y = stoi(privacy.substr(0, 4));
        int start_m = stoi(privacy.substr(5, 2));
        int start_d = stoi(privacy.substr(8, 2));
        int start_total = start_y * YEAR + start_m * MONTH + start_d + termMap[privacy[11]] - 1;
        
        if (today_total > start_total) answer.push_back(i);
    }
    return answer;
}