#include <iostream>
#include <string>
#include <vector>

using namespace std;

void UpdateAnswer(vector<int>& duration, vector<int>& answer) {
    int count = 0;
    while (!duration.empty()) {
        duration.pop_back();
        count++;
    }
    answer.push_back(count);
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, duration;
    int left, longest;
    
    for (int i = 0; i < progresses.size(); i++) {
        left = 100 - progresses[i];
        left = left % speeds[i] ? left / speeds[i] + 1 : left / speeds[i];
        
        if (i == 0)
            longest = left;
        
        else if (longest < left) {
            UpdateAnswer(duration, answer);
            longest = left;
        }
        duration.push_back(left);
    }
    UpdateAnswer(duration, answer);
    return answer;
}