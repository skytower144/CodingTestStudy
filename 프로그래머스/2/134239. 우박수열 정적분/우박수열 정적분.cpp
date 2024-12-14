#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> areas(1, 0);

void InitArea(int k)
{
    while (k > 1)
    {
        int prevK = k;
        k = k % 2 ? k * 3 + 1 : k * 0.5;
        
        double area = max(prevK, k) - abs(prevK - k) * 0.5;
        areas.push_back(areas.back() + area);
    }
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    InitArea(k);
    int n = areas.size() - 1;
    
    for (const auto& range : ranges)
    {
        int start = range[0];
        int end = n - (-range[1]);
        
        if (start > end)
        {
            answer.push_back(-1);
            continue;
        }
        
        answer.push_back(areas[end] - areas[start]);      
    }
    
    return answer;
}