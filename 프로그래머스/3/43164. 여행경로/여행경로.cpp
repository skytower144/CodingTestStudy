#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, vector<pair<string, bool>>> ticketMap;
vector<string> answer;
int MAX_COUNT;

void GetPath(string from, vector<string>& temp, int count)
{
    if (count >= MAX_COUNT)
    {
        if (answer.empty())
            answer = temp;
        else
        {
            int length = min(answer.size(), temp.size());

            for (int i = 0; i < length; i++)
            {
                if (temp[i] == answer[i])
                    continue;
                
                if (temp[i] < answer[i])
                    answer = temp;
                
                return;
            }
        }
        
        return;
    }
    
    for (auto& value : ticketMap[from])
    {
        if (value.second)
            continue;
        
        value.second = true;
        temp.push_back(value.first);
        
        GetPath(value.first, temp, count + 1);
        
        value.second = false;
        temp.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    ticketMap = unordered_map<string, vector<pair<string, bool>>>();
    MAX_COUNT = tickets.size();
    
    for (int i = 0; i < tickets.size(); i++)
    {
        pair<string, bool> value = {tickets[i][1], false};
        ticketMap[tickets[i][0]].push_back(value);
    }
    
    vector<string> temp;
    temp.push_back("ICN");
    GetPath("ICN", temp, 0);
    
    return answer;
}