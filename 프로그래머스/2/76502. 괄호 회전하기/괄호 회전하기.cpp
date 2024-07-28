#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, char> bracketMap = {
    {'{', '}'},
    {'[', ']'},
    {'(', ')'}
};

bool CheckValid(string& sentence)
{
    string temp = "";
    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == '[' || (sentence[i] == '(' || sentence[i] == '{'))
            temp.push_back(sentence[i]);
        
        else if (sentence[i] == ']' || (sentence[i] == ')' || sentence[i] == '}'))
        {
            if (temp.size() == 0)
                return false;
            
            char c = temp.back();
            temp.pop_back();
            
            if (bracketMap[c] != sentence[i])
                return false;
        }
    }
    return temp.size() == 0;
}

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (CheckValid(s))
        {
            ++answer;
        }
        char c = s[0];
        s = s.substr(1, s.size() - 1) + c;
    }
    return answer;
}