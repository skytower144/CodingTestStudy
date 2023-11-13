#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0, index = 0;
    vector<int> threes;
    
    for (int i = 0; ; i++) {
        if (pow(3, i) > n) {
            index = i - 1;
            break;
        }
        else if (pow(3, i) == n) {
            index = i;
            break;
        }
    }
    while (n > 0) {
        threes.push_back(n / (int)pow(3, index));
        n %= (int)pow(3, index);
        index--;
    }
    for (int i = 0; i < threes.size(); i++)
        answer += pow(3, i) * threes[i];
    return answer;
}