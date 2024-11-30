#include <string>
#include <vector>
#include <iostream>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int n = a % b;
        a = b;
        b = n;
    }
    return a;
}

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int gcd1 = arrayA[0];
    int gcd2 = arrayB[0];
    
    for (int i = 1; i < arrayA.size(); i++)
        gcd1 = gcd(gcd1, arrayA[i]);
    
    for (int i = 1; i < arrayB.size(); i++)
        gcd2 = gcd(gcd2, arrayB[i]);
    
    bool condition1 = true;
    
    for (int i = 0; i < arrayA.size(); i++)
    {
        if (arrayA[i] % gcd2 == 0)
        {
            condition1 = false;
            break;
        }
    }
    
    if (condition1)
        answer = gcd2;
    
    bool condition2 = true;
    
    for (int i = 0; i < arrayB.size(); i++)
    {
        if (arrayB[i] % gcd1 == 0)
        {
            condition2 = false;
            break;
        }
    }
    
    if (condition2)
        answer = max(answer, gcd1);
    
    return answer;
}