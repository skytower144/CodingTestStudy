#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

const int MAX = 100000001;

int solution(int storey) {
    int answer = 0;
    
    while (storey)
    {
        int left = storey % 10;
        storey /= 10;
        
        if (left < 5)
            answer += left;            
        
        else if (left > 5)
        {
            storey++;
            answer += 10 - left;
        }
        
        else
        {
            if (storey % 10 < 5)
                answer += left;
            else
            {
                storey++;
                answer += 10 - left;
            }
        }
    }
    
    return answer;
}