#include <string>
#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

long long answer = 0;
ll N;

void FindSolution(ll duration, vector<int>& times)
{
    ll left = 0;
    ll right = duration;
    ll mid;
    
    while (left <= right)
    {
        mid = left * 0.5 + right * 0.5;
        ll count = 0;
                
        for (int i = 0; i < times.size(); i++)
            count += mid / times[i];
        
        if (count < N)
            left = mid + 1;
        else
        {
            answer = min(answer, mid);
            right = mid - 1;
        }
    }
}

long long solution(int n, vector<int> times) {
    N = n;
    ll minDuration = ll(times[0]) * ll(n);
    
    for (int i = 1; i < times.size(); i++)
        minDuration = min(minDuration, ll(times[i]) * ll(n));

    answer = minDuration;
    FindSolution(minDuration, times);
    
    return answer;
}