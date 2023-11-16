#include <string>
#include <vector>

using namespace std;

int leftOver = 0;

int CalculateBottle(int emptyCoke, int rewardCoke, int n) {
    int count = 0;
    
    while (n > 0) {
        while (n % emptyCoke) {
            leftOver++;
            n--;
        }
        n = (n / emptyCoke) * rewardCoke;
        count += n;
    }
    return count;
}

int solution(int emptyCoke, int rewardCoke, int n) {
    int answer = 0, amount = 0;
    
    while (true) {
        amount = CalculateBottle(emptyCoke, rewardCoke, n);
        
        if (amount) {
            answer += amount;
            n = leftOver;
            leftOver = 0;
        }
        else break;
    }
    return answer;
}