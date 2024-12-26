#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    bool isSkip[26] = {false, };
    
    for (const auto& c : skip)
        isSkip[c - 'a'] = true;

    for (char& c : s)
    {
        for (int i = 0; i < index; i++)
        {
            c++;
            
            if (c > 'z')
                c = 'a';
            
            if (isSkip[c - 'a'])
                i--;
        }
    }
    
    return s;
}