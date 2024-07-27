#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int> skillMap;
    
    for (const auto& c : skill)
        skillMap[c] = 1;
    
    for (const auto tree : skill_trees)
    {
        int index = 0;
        bool isPossibleTree = true;
        
        for (const auto currentSkill : tree)
        {
            if (skillMap.count(currentSkill))
            {
                if (skill[index] == currentSkill)
                    index++;
                else
                {
                    isPossibleTree = false;
                    break;
                }
            }
        }
        if (isPossibleTree)
            answer++;
    }
    return answer;
}