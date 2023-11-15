#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    map<string, string> wordMap = {
        {"zero", "0"}, {"one", "1"},
        {"two", "2"},  {"three", "3"},
        {"four", "4"}, {"five", "5"},
        {"six", "6"},  {"seven", "7"},
        {"eight", "8"},{"nine", "9"}
    };
    string temp = "";
    string word = "";
    
    for (auto c : s) {
        if (isdigit(c)) {
            word += c;
            continue;
        }
        temp += c;
        if (wordMap.count(temp)) {
            word += wordMap[temp];
            temp = "";
        }
    }
    return stoi(word);
}