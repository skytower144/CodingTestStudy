#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); i++) {
        int index = -1;
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                index = j;
                break;
            }
        }
        if (index == - 1)
            index = prices.size() - 1;
        answer.push_back(index - i);
    }
    return answer;
}