#include <string>
#include <vector>
#include <iostream>

using namespace std;

char alpha[] = {'A', 'E', 'I', 'O', 'U'};
bool flag = false;
int answer;

void GetWordNum(string& current, string& word, int count) {
    if (count == 5)
        return;
    
    for (int i = 0; i < 5; i++) {
        if (flag)
            return;
        
        current.push_back(alpha[i]);
        answer++;
        
        if (current == word) {
            flag = true;
            return;
        }
        GetWordNum(current, word, count + 1);
        current.pop_back();
    }
}

int solution(string word) {
    answer = 0;
    string current = "";
    GetWordNum(current, word, 0);
    
    return answer;
}