#include <string>
#include <vector>

using namespace std;

int GetFactors(int n) {
    int factors = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) factors++;
    return factors;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        if (GetFactors(i) % 2) answer -= i;
        else answer += i;
    }
    return answer;
}