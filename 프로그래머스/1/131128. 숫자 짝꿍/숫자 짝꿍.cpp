#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int> xMap, yMap;
    
    for (const auto x : X) xMap[x]++;
    for (const auto y : Y) yMap[y]++;
    
    for (const auto [num, count] : xMap)
        if (yMap.count(num)) answer += string(min(yMap[num], count), num);
    
    sort(answer.begin(), answer.end(), greater());
    return answer.size() ? (answer[0] == '0' ? "0" : answer) : "-1";
}