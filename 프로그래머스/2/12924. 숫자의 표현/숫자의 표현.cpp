#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int left = 1, right = 1, sum = 1;
    
    while (left <= right) {
        if (sum == n)
            answer++;
    
        if (sum <= n) {
            right++;
            sum += right;
        }
        else {
            sum -= left;
            left++;
        }
    }
    return answer;
}