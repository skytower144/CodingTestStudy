#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    return a.size() < b.size();
}

vector<vector<int>> ConvertToVector(string s)
{
    vector<vector<int>> nums;
    nums.push_back({});
    
    string numString = "";
    int index = 0;
    bool isBracketOpen = false;
    
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == '{')
            isBracketOpen = true;
        
        else if (s[i] == '}')
        {
            isBracketOpen = false;
            nums[index].push_back(stoi(numString));
            numString = "";
            index++;
            nums.push_back({});
            
        }
        else if (isBracketOpen && s[i] == ',')
        {
            nums[index].push_back(stoi(numString));
            numString = "";
        }
        else if (isdigit(s[i]))
            numString += s[i];
    }
    return nums;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> nums;
    nums = ConvertToVector(s);
    unordered_map<int, int> numMap;
    
    sort(nums.begin(), nums.end(), compare);
    
    for (const auto& numVec : nums)
    {
        for (const auto& num : numVec)
        {
            if (!numMap.count(num))
            {
                answer.push_back(num);
                numMap[num] = 1;
            }
        }
    }
    return answer;
}