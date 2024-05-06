#include <string>
#include <vector>
#define LIMIT 10000000

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1, 0);
    
    for (int i = 1; i <= LIMIT && i <= end / 2; i++) {
        int start = begin % i ? begin / i + 1 : begin / i;
        if (start == 1) start++;
        
        for (int j = start; i * j <= end; j++)
            answer[i * j - begin] = i;
    }
    return answer;
}