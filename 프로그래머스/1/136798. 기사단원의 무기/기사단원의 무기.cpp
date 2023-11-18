#include <string>
#include <vector>

using namespace std;

int GetFactors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) count++;
        else if (n % i == 0) count += 2;
    }
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0, count = 0;
    for (int i = 1; i <= number; i++) {
        count = GetFactors(i);
        answer += count > limit ? power : count;
    }
    return answer;
}