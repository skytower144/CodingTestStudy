#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0, painted = 0;
    
    for (auto part : section) {
        if (painted < part) {
            painted = part + m - 1;
            answer++;
        }
    }
    return answer;
}