#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare (string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> stringNum;
    
    for (const auto& num : numbers)
        stringNum.push_back(to_string(num));
    
    sort(stringNum.begin(), stringNum.end(), compare);

    for (const auto& num : stringNum)
        answer += num;
    
    if (answer[0] == '0') answer = "0";
    return answer;
}