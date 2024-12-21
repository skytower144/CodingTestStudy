#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int idx = n - 1;
    
    while (idx >= 0)
    {
        vector<int> dStack, pStack;
        int dSum = 0, pSum = 0;
        bool dFull = false;
        bool pFull = false;
        
        bool isBreak = true;
        
        for (int i = idx; i >= 0; i--)
        {
            if (deliveries[i] != 0 || pickups[i] != 0)
            {
                isBreak = false;             
                break;
            }
        }
        
        if (isBreak)
            break;
        
        for (int i = idx; i >= 0; i--)
        {
            if (!dFull && deliveries[i] > 0)
            {
                if (dSum + deliveries[i] <= cap)
                {
                    dStack.push_back(i);
                    dSum += deliveries[i];
                    deliveries[i] = 0;
                }
                else
                {
                    dStack.push_back(i);
                    deliveries[i] -= cap - dSum;
                    dFull = true;
                }
            }

            if (!pFull && pickups[i] > 0)
            {
                if (pSum + pickups[i] <= cap)
                {
                    pStack.push_back(i);
                    pSum += pickups[i];
                    pickups[i] = 0;
                }
                else
                {
                    pStack.push_back(i);
                    pickups[i] -= cap - pSum;
                    pFull = true;
                }
            }

            if (dFull && pFull)
                break;
        }
        
        int farthest = 0;
        int nextIdx = -1;
        
        if (!dStack.empty())
        {
            nextIdx = dStack.back();
            farthest = dStack[0];
        }
        
        if (!pStack.empty())
        {
            nextIdx = max(nextIdx, pStack.back());            
            farthest = max(farthest, pStack[0]);
        }
        
        answer += (farthest + 1) * 2;
        idx = nextIdx;
    }
    
    return answer;
}