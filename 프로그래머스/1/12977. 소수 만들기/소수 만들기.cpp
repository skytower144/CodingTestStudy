#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = 0;
const int MAX = 1000 * 50 + 1;
vector<bool> isPrime(MAX, true);

void InitPrime()
{
    isPrime[1] = false;
    
    for (int i = 2; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;
        
        for (int j = 2; i * j <= MAX; j++)
            isPrime[i * j] = false;
    }
}

void Comb(vector<int>& nums, int sum, int count, int idx)
{
    if (count >= 3)
    {
        if (isPrime[sum])
            answer++;
        return;
    }
    
    for (int i = idx; i < nums.size(); i++)
        Comb(nums, sum + nums[i], count + 1, i + 1);
}

int solution(vector<int> nums) {
    InitPrime();
    Comb(nums, 0, 0, 0);
    
    return answer;
}