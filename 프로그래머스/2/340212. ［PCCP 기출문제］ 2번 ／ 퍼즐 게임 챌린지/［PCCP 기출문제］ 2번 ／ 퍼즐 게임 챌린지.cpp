#include <string>
#include <vector>
#include <iostream>

using ll = long long;
using namespace std;

ll GetDuration(ll level, ll diff, ll time_cur, ll time_prev)
{
    if (diff <= level)
        return time_cur;
    
    return (diff - level) * (time_cur + time_prev) + time_cur;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1;
    int right = 0;
    
    for (int i = 0; i < diffs.size(); i++)
        right = max(right, diffs[i]);
    
    int answer = right;
    
    while (left <= right)
    {
        int mid = (left + right) * 0.5;
        int level = mid;
        
        if (level <= 0)
            break;
        
        ll duration = 0;
        
        for (int i = 0; i < diffs.size(); i++)
        {
            if (i == 0)
            {
                duration += times[0];
                continue;
            }
            
            duration += GetDuration(level, diffs[i], times[i], times[i - 1]);
        }
        
        if (duration <= limit)
        {
            answer = min(answer, level);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return answer;
}