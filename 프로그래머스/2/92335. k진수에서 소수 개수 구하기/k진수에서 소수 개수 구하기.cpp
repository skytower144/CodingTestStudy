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
    return converted;
}

int solution(int n, int k) {
    int answer = 0;
   
    string converted = ConvertBase(n, k);
    string temp = "";
    
    for (int i = 0; i < converted.size(); i++)
    {
        if (converted[i] != '0')
            temp += converted[i];
        
        else if  (temp != "")
        {
            long long num = stoull(temp);
            if (IsPrime(num))
                ++answer;
            
            temp = "";
        }
    }
    if (temp != "")
    {
        long long num = stoull(temp);
        if (IsPrime(num))
            ++answer;
    }
    return answer;
}