#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

bool compare(string& a, string& b)
{
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    int n = phone_book.size();
    unordered_map<string, int> phoneDict;
    
    sort(phone_book.begin(), phone_book.end(), compare);
    
    phoneDict[phone_book[0]]++;

    for (int i = 1; i < phone_book.size(); i++)
    {
        string key = "";
        int k = phone_book[i - 1].size();
        
        for (int j = 0; j < k; j++)
        {
            key += phone_book[i][j];
            
            if (phoneDict.count(key) > 0)
                return false;
        }
        phoneDict[phone_book[i]]++;
    }
    
    return answer;
}