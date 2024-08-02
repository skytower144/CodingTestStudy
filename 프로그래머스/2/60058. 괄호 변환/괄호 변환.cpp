#include <string>
#include <vector>
#include <iostream>

using namespace std;

string EditBracket(string p)
{
    vector<char> brackets;
    int openBrackets = 0, closedBrackets = 0;
    bool isCorrectBracket = true;
    int i;
    
    for (i = 0; i < p.size(); i++)
    {
        char c = p[i];
        if (c == '(')
        {
            openBrackets++;
            brackets.push_back(c);
        }
        else if (c == ')')
        {
            closedBrackets++;
            
            if (brackets.size() == 0)
                isCorrectBracket = false;
            else
                brackets.pop_back();
        }
        if (openBrackets == closedBrackets)
            break;
    }
    if (openBrackets != closedBrackets)
        isCorrectBracket = false;
    
    string left = p.substr(0, min(i + 1, (int)p.size()));
    string right = "";
    
    if (i + 1 <= p.size() - 1)
        right = p.substr(i + 1);
    
    if (isCorrectBracket)
    {
        if (right != "")
            return left + EditBracket(right);
        return left;
    }
    else
    {
        if (right != "")
            right = EditBracket(right);
        
        string vTemp = "(" + right + ")";
        string uTemp = "";
        
        if (left.size() >= 2)
        {
            uTemp = left.substr(1, left.size() - 2);
            for (int i = 0; i < uTemp.size(); i++)
            {
                if (uTemp[i] == ')')
                    uTemp[i] = '(';
                else
                    uTemp[i] = ')';
            }
        }
        return vTemp + uTemp;
    }
}

string solution(string p) {
    string answer = "";
    answer = EditBracket(p);
    
    return answer;
}