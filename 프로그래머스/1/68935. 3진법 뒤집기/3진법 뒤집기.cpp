#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> threes;
    
    while (n) {
        threes.push_back(n % 3);
        n /= 3;
    }
    for (int i = 0; i < threes.size(); i++)
        answer += pow(3, i) * threes[threes.size() - 1 - i];
    return answer;
}