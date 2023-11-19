#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    map<char, int> skipMap;
    for (auto c : skip) skipMap[c]++;
    
    for (auto c : s) {
        int count = 0;
        while (count < index) {
            c++;
            count++;
            if (c == 'z' + 1) c = 'a';
            if (skipMap.count(c)) count--;
        }
        answer += c;
    }
    return answer;
}