#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;

    sort(targets.begin(), targets.end(), compare);
    int firePoint = targets[0][1] - 1;
    
    for (int i = 1; i < targets.size(); i++)
    {
        if (firePoint >= targets[i][0])
        {
            firePoint = min(firePoint, targets[i][1] - 1);
            continue;
        }
        
        answer++;
        firePoint = targets[i][1] - 1;
    }
    
    return answer;
}