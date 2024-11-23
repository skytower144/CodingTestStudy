#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long targetSum = 0;
    long long currentSum = 0;
    
    vector<int> merged;
    
    for (int i = 0; i < queue1.size(); i++)
    {
        merged.push_back(queue1[i]);
        targetSum += queue1[i];
    }
    currentSum = targetSum;
    
    for (int i = 0; i < queue1.size(); i++)
    {
        merged.push_back(queue2[i]);
        targetSum += queue2[i];
    }
    targetSum /= 2;
    
    int left = 0;
    int right = queue1.size();
    
    while (left <= right && right < merged.size())
    {
        if (currentSum < targetSum)
        {
            currentSum += merged[right];
            right++;
        }
        else if (currentSum > targetSum)
        {
            currentSum -= merged[left];
            left++;
        }
        else
            return answer;
        
        answer++;
    }
    return -1;
}