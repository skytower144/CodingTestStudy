#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothesDict;
    
    for (int i = 0; i < clothes.size(); i++)
        clothesDict[clothes[i][1]]++;
    
    for (const auto& [wearType, count] : clothesDict)
        answer *= (count + 1);
    
    return answer - 1;
}