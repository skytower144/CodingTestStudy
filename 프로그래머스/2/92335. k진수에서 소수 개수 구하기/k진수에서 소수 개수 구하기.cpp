#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool IsPrime(long long n)
{
    if (n == 1)
        return false;
    
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

string ConvertBase(int n, int k)
{
    string converted = "";
    while (n)
    {
        converted = to_string(n % k) + converted;
        n /= k;
    }
    converted += '0';
    return converted;
}

int solution(int n, int k) {
    int answer = 0;
   
    string converted = ConvertBase(n, k);
    long long temp = 0;    
   
    for (int i = 0; i < converted.size(); i++)
    {
        if (converted[i] != '0')
            temp = temp * 10 + converted[i] - '0';
        
        else if (temp > 0)
        {
            answer += IsPrime(temp);
            temp = 0;
        }
    }
    return answer;
}