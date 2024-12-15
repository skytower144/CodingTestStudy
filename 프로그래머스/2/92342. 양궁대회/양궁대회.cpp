#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int maxDiff = -1;
vector<int> answer;

void Comb(vector<int>& selected, vector<int>& info, int idx, int count, int pPoint, int rPoint, int n)
{
    for (int i = idx; i <= 10; i++)
    {
        if (count + info[i] + 1 > n)
        {
            if (info[i] > 0)
                pPoint += 10 - i;
            
            selected[i] = 0;
            continue;
        }
        
        selected[i] = info[i] + 1;
        Comb(selected, info, i + 1, count + info[i] + 1, pPoint, rPoint + 10 - i, n);
        
        selected[i] = 0;
        
        if (info[i] > 0)
            pPoint += 10 - i;
    }
    
    if (pPoint >= rPoint)
        return;
    
    int curDiff = rPoint - pPoint;
    
    if (maxDiff > curDiff)
        return;
    
    if (count < n)
    {
        for (int i = 0; i <= 10; i++)
        {
            if (selected[10 - i] == 0)
            {
                int amount = min(n - count, info[10 - i]);
                selected[10 - i] += amount;
                
                count += amount;
                
                if (count == n)
                    break;
            }
            else
            {
                selected[10 - i] += n - count;
                break;
            }
        }
    }
    
    if (answer.empty())
    {
        maxDiff = curDiff;
        answer = selected;
        return;
    }
    
    if (maxDiff == curDiff)
    {
        for (int i = 10; i >= 0; i--)
        {
            if (answer[i] == selected[i])
                continue;
            
            if (answer[i] < selected[i])
                answer = selected;
            
            return;
        }
        
        return;
    }
    
    maxDiff = curDiff;
    answer = selected;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> selected(11, 0);
    
    Comb(selected, info, 0, 0, 0, 0, n);
    
    if (answer.empty())
        answer = {-1};
    
    return answer;
}