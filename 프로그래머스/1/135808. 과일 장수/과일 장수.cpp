#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0, size = score.size();
    sort(score.begin(), score.end());
    
    for (int i = size - 1; i >= 0; i -= m)
        if (i - m + 1 >= 0) answer += score[i - m + 1] * m;
    return answer;
}