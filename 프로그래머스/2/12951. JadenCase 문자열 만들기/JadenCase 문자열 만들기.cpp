#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string word;
    bool flag = false;
    
    for (const auto& c : s) {
        if (c == ' ') {
            flag = false;
            answer += c;
        }
        else if (!flag) {
            flag = true;
            answer += toupper(c);
        }
        else
            answer += tolower(c);
    }
    return answer;
}