#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    vector<char> stack;
    
    for (const auto& c : s) {
        if (c == '(')
            stack.push_back(c);
        
        else if (!stack.empty() && stack.back() == '(')
            stack.pop_back();
        else
            return false;
    }
    return stack.empty();
}