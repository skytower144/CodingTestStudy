#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), compare);

    int lastCam = routes[0][1];
    answer++;

    for (int i = 1; i < routes.size(); i++)
    {
        if (lastCam < routes[i][0])
        {
            answer++;
            lastCam = routes[i][1];
        }
    }
    
    return answer;
}