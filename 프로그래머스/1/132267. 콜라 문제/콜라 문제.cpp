#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int left = 0;
    
    while (n >= a)
    {
        int newBottles = n / a * b;
        
        if (n % a)
            left += n % a;
        
        answer += newBottles;
        n = newBottles;
        
        if (n + left >= a)
        {
            n += left;
            left = 0;
        }
    }
    
    return answer;
}