#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long GetSmallestNum(long long num)
{
    int i = 0;
    while (num & (1LL << i)) ++i;
    
    if (i == 0)
        return num + 1;
    
    num |= (1LL << i);
    num &= ~(1LL << (i - 1));
    return num;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long num : numbers)
        answer.push_back(GetSmallestNum(num));
    return answer;
}