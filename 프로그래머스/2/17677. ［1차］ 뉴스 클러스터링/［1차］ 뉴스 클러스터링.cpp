#include <string>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

bool CheckIgnore(string& word) {
    for (const auto& c : word) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
            return true;
    }
    return false;
}
void ToLower(string& word) {
    for (auto& c : word) {
        if (c >= 'A' && c <= 'Z')
            c = char(c + 'a' - 'A');
    }
}
void CreateComb(string& inputString, int *arr) {
    string temp;
    for (int i = 0; i < inputString.size() - 1; i++) {
        temp = string(1, inputString[i]) + inputString[i + 1];
        
        if (CheckIgnore(temp))
            continue;
        
        ToLower(temp);
        arr[(temp[0] - 'a') * 26 + (temp[1] - 'a')]++;
    }
}
int solution(string str1, string str2) {
    int answer = 0;
    int c1[676] = {0,};
    int c2[676] = {0,};
    
    CreateComb(str1, c1);
    CreateComb(str2, c2);
    
    int interCt = 0;
    int unionCt = 0;
    
    for (int i = 0; i < 676; i++) {
        interCt += min(c1[i], c2[i]);
        unionCt += max(c1[i], c2[i]);
    }
    answer = unionCt ? floor((double)interCt / unionCt * 65536) : 65536;
    return answer;
}