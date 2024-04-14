#include <string>
#include <climits>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    stringstream ss(s);
    string num;
    
    while (ss >> num) {
        maxNum = max(maxNum, stoi(num));
        minNum = min(minNum, stoi(num));
    }
    answer = to_string(minNum) + " " + to_string(maxNum);
    return answer;
}