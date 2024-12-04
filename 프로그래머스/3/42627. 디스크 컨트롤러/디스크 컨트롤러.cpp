#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 순서: 소요시간, 요청시각, 번호
// 요청시각, 소요시간
// jobs : [0, 3], [1, 9], [3, 5]

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int totalJobs = jobs.size();
    
    for (int i = 0; i < jobs.size(); i++)
        jobs[i].push_back(i);
    
    priority_queue<vector<int>> pq;
    int currentTime = 0;
    
    while (!(jobs.empty() && pq.empty()))
    {
        for (int i = jobs.size() - 1; i >= 0; i--)
        {
            if (currentTime >= jobs[i][0])
            {
                pq.push({-jobs[i][1], -jobs[i][0], -jobs[i][2]});
                jobs.erase(jobs.begin() + i);
            }
        }

        if (!pq.empty())
        {
            vector<int> popped = pq.top();
            pq.pop();

            currentTime += -popped[0];
            answer += currentTime - (-popped[1]);
        }
        else
            currentTime++;
    }
    
    answer = answer / totalJobs;
    return answer;
}