#include <string>
#include <vector>

using namespace std;

int solution(int emptyCoke, int rewardCoke, int n) {
    int answer = 0;
    while (n >= emptyCoke) {
        answer += rewardCoke;
        n -= emptyCoke - rewardCoke; // n = n - emptyCoke + rewardCoke;
    }
    return answer;
}