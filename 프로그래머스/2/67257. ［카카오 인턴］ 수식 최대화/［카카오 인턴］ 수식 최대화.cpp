#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

long long answer = 0;
unordered_set<char> opTypes;
vector<char> pureOpList;
vector<char> opList;
vector<long long> numList;

void ConvertNumlist(char op, vector<long long>& tempList, vector<char>& tempOpList)
{
    for (int i = 0; i < tempOpList.size(); i++)
    {
        if (tempOpList[i] == op)
        {
            switch (op)
            {
                case '-':
                    tempList[i] = tempList[i] - tempList[i + 1];
                    break;

                case '+':
                    tempList[i] = tempList[i] + tempList[i + 1];
                    break;

                case '*':
                    tempList[i] = tempList[i] * tempList[i + 1];
                    break;
            }
            for (int j = i + 1; j < tempList.size() - 1; j++)
                tempList[j] = tempList[j + 1];
            
            for (int j = i; j < tempOpList.size() - 1; j++)
                tempOpList[j] = tempOpList[j + 1];
            
            tempList.resize(tempList.size() - 1);
            tempOpList.resize(tempOpList.size() - 1);
            i--;
        }
    }
}

void Comb(int count, vector<char>& temp, vector<bool>& check)
{
    if (count == pureOpList.size())
    {
        int result = 0;
        vector<long long> tempList = numList;
        vector<char> tempOpList = opList;
        
        for (auto op : temp)
        {
            ConvertNumlist(op, tempList, tempOpList);
        }
        answer = max(answer, abs(tempList[0]));
        return;
    }
    for (int i = 0; i < pureOpList.size(); i++)
    {
        if (check[i])
            continue;
        
        temp.push_back(pureOpList[i]);
        check[i] = true;
        
        Comb(count + 1, temp, check);
        
        check[i] = false;
        temp.pop_back();
    }
}

void ParseExpression(vector<char>& opList, vector<long long>& numList, string expression)
{
    string temp = "";
    for (auto c : expression)
    {
        if (c >= '0' && c <= '9')
            temp += c;
        else
        {
            numList.push_back(stoi(temp));
            opList.push_back(c);
            opTypes.insert(c);
            temp = "";
        }
    }
    numList.push_back(stoi(temp));
}

long long solution(string expression) {
    
    ParseExpression(opList, numList, expression);
    for (char op : opTypes)
        pureOpList.push_back(op);
    
    vector<char> temp;
    vector<bool> check(pureOpList.size(), false);
    Comb(0, temp, check);
    
    return answer;
}