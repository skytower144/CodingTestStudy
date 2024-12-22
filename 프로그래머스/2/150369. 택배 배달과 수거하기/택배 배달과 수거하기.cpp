#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Unload(int j, int cap, vector<int>& loadList)
{
    int unloaded = 0;
    
    while (j >= 0 && unloaded <= cap)
    {
        if (unloaded + loadList[j] >= cap)
        {
            loadList[j] -= cap - unloaded;
            unloaded = cap;
            break;
        }

        unloaded += loadList[j];
        loadList[j] = 0;
        j--;
    }
    
    return unloaded;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (deliveries[i] > 0 || pickups[i] > 0)
        {
            Unload(i, cap, deliveries);
            Unload(i, cap, pickups);
            
            answer += (i + 1) * 2;
        }
        
        if (deliveries[i] > 0 || pickups[i] > 0)
            i++;
    }
    
    return answer;
}