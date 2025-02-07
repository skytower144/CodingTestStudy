#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int compIndex = 0;

bool compare(vector<int>& a, vector<int>& b)
{
    if (a[compIndex] != b[compIndex])
        return a[compIndex] < b[compIndex];
    
    
    return a[0] > b[0];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    col -= 1;
    
    sort(data.begin(), data.end(), [col](auto& a, auto& b)
         {
             if (a[col] != b[col])
                 return a[col] < b[col];
             
             return a[0] > b[0];
         }
    );

    for (int i = row_begin - 1; i <= row_end - 1; i++)
    {
        int modSum = 0;
        
        for (int j = 0; j < data[i].size(); j++)
            modSum += data[i][j] % (i + 1);
        
        answer ^= modSum;
    }
    
    return answer;
}