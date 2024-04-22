#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    vector<char> stack;
    
    for (const auto& c : s) {
        if (stack.empty())
            stack.push_back(c);
        else if (stack.back() == c)
            stack.pop_back();
        else
            stack.push_back(c);
    }
    return (int)stack.empty();
}