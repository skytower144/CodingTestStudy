#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

int N;

int GetSum(vector<int>& elements, int start, int length)
{
    int sum = 0;
    int k = start + length;
    
    for (int i = start; i < k; i++)
    {
        sum += elements[i % N];
    }
    return sum;
}

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int> nums;

    N = elements.size();
    
    for (int i = 1; i < elements.size(); i++)
    {
        for (int j = 0; j < elements.size(); j++)
            nums.insert(GetSum(elements, j, i));
    }
    nums.insert(GetSum(elements, 0, N));
    
    answer = nums.size();    
    return answer;
}