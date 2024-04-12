#include <string>
#include <vector>
#include <iostream>

using namespace std;

int CountOnes(int n) {
    int count = 0;
    while (n) {
        count += n % 2;
        n /= 2;
    }
    return count;
}
int solution(int n) {
    int other = n + 1;
    int quota = CountOnes(n);
    
    while (CountOnes(other) != quota)
        other++;
    return other;
}