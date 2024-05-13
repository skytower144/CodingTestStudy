#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for (const auto& num : number) {
        while(answer != "" && answer.back() < num && k) {
            answer.pop_back();
            k--;
        }
        answer += num;
    }
    while (k--)
        answer.pop_back();
    return answer;
}