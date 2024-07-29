#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    # 키를 만들 때 속성들을 문자열로 한 후, 붙이는 방식으로 비교하면 안되는 이유:
    ex) 10 ryan
        1  0ryan
    => 해당 2개의 키는 다르지만, 중복이 발생했다고 판단하게 된다.
*/

bool compare(vector<int>& a, vector<int>& b)
{
    return a.size() < b.size();
}

void CreateEveryKey(vector<vector<int>>& everyKeys, vector<int>& atr, vector<int> temp, int index)
{
    for (int i = index; i < atr.size(); i++)
    {
        temp.push_back(atr[i]);
        CreateEveryKey(everyKeys, atr, temp, i + 1);
        temp.pop_back();
    }
    everyKeys.push_back(temp);
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    unordered_map<string, int> keyAtrMap;
    vector<vector<int>> everyKeys;
    vector<int> atr;
    vector<int> temp;
    
    for (int i = 0; i < relation[0].size(); i++)
        atr.push_back(i);
    
    CreateEveryKey(everyKeys, atr, temp, 0);
    sort(everyKeys.begin(), everyKeys.end(), compare);
    
    for (int k = 0; k < everyKeys.size(); k++)
    {
        unordered_map<string, int> possibleKeys;
        bool isPossibleKey = true;
        
        vector<vector<int>> subKeys;
        vector<int> temp2;
        CreateEveryKey(subKeys, everyKeys[k], temp2, 0);
        
        for (const auto& subKey : subKeys)
        {
            string key = "";
            for (const auto& subKeyAtr : subKey)
                key += to_string(subKeyAtr);
            
            if (keyAtrMap.count(key))
            {
                isPossibleKey = false;
                break;
            }
        }
        if (isPossibleKey)
        {
            for (int i = 0; i < relation.size(); i++)
            {
                string key = "";
                for (const auto& j : everyKeys[k])
                    key += ('_' + relation[i][j]);

                if (possibleKeys.count(key))
                {
                    isPossibleKey = false;
                    break;
                }
                possibleKeys[key] = 1;
            }
        }
        if (isPossibleKey)
        {
            string keyAtr = "";
            for (const auto& j : everyKeys[k])
                keyAtr += to_string(j);
            
            keyAtrMap[keyAtr] = 1;
            answer++;
        }
    }
    return answer;
}