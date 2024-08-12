#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int minCourse, maxCourse;
int maxOrderCounts[11] = {0,};
int courseIndexes[11] = {0,};
unordered_map<string, int> courseMap;
vector<vector<string>> maxOrderNames;

void CourseComb(int index, string& comb, const string& fullComb)
{
    int combLength = comb.size();
    
    if (courseIndexes[combLength])
    {
        string temp = comb;
        sort(temp.begin(), temp.end());
        
        ++courseMap[temp];
        if (maxOrderCounts[combLength] <= courseMap[temp])
        {
            if (maxOrderCounts[combLength] < courseMap[temp])
            {
                maxOrderNames[combLength].clear();
                maxOrderNames[combLength].resize(0);
            }
            maxOrderCounts[combLength] = courseMap[temp];
            maxOrderNames[combLength].push_back(temp);
        }
        if (combLength == maxCourse)
            return;
    }
    for (int i = index; i < fullComb.size(); i++)
    {
        comb.push_back(fullComb[i]);
        CourseComb(i + 1, comb, fullComb);
        comb.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    maxOrderNames = vector<vector<string>>(11);
    
    maxCourse = course.back();
    for (const int& i : course)
        courseIndexes[i] = 1;
    
    for (const string& order : orders)
    {
        string comb = "";
        CourseComb(0, comb, order);
    }
    for (const int& i : course)
    {
        for (auto name : maxOrderNames[i])
        {
            if (maxOrderCounts[i] >= 2)
                answer.push_back(name);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}