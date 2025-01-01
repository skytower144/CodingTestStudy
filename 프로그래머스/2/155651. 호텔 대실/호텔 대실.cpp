#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<pair<int, int>> bookTime;
    char split = ':';
    int hour, minutes;
    int startTime, endTime;
    
    for (const auto& timeTag : book_time)
    {
        stringstream ss(timeTag[0]);
        ss >> hour >> split >> minutes;
        
        startTime = hour * 60 + minutes;
        
        ss = stringstream(timeTag[1]);
        ss >> hour >> split >> minutes;
        endTime = hour * 60 + minutes;

        bookTime.push_back({startTime, endTime});
    }
    
    sort(bookTime.begin(), bookTime.end());
    
    endTime = bookTime[0].second;
    
    priority_queue<int> pq;
    pq.push(-endTime);
    
    for (int i = 1; i < bookTime.size(); i++)
    {
        int nextStart = bookTime[i].first;
        int nextEnd = bookTime[i].second;
        
        int closestEndTime = -pq.top() + 10;
        
        if (!pq.empty() && closestEndTime <= nextStart)
            pq.pop();
        
        pq.push(-nextEnd);
    }

    answer = pq.size();
    return answer;
}