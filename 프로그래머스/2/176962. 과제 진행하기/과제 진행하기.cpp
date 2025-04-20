#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Plan
{
    string subject;
    int startTime;
    int duration;
};

bool compare(Plan& a, Plan& b)
{
    return a.startTime < b.startTime;
}

int CalcTime(int currentTime, int duration)
{
    int minutes = (currentTime % 100) + duration;
    return (currentTime / 100 + minutes / 60) * 100 + (minutes % 60);
}

int TimeDiff(int time1, int time2)
{
    int minutes1 = (time1 / 100) * 60 + (time1 % 100);
    int minutes2 = (time2 / 100) * 60 + (time2 % 100);
    return abs(minutes1 - minutes2);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Plan> times;
    
    for (auto info : plans)
    {
        stringstream ss(info[1]);
        int hour, minute, duration;
        char c;
        ss >> hour >> c >> minute;
        
        Plan plan = { info[0], hour * 100 + minute, stoi(info[2]) };
        times.push_back(plan);
    }
    
    sort(times.begin(), times.end(), compare);
    vector<Plan> stack;
    int currentTime = times[0].startTime;
    
    for (int i = 0; i < times.size(); i++)
    {
        if (i == times.size() - 1)
        {
            answer.push_back(times[i].subject);
            currentTime = CalcTime(currentTime, times[i].duration);
            break;    
        }
        
        int nextTime = times[i + 1].startTime;
        int destTime = CalcTime(currentTime, times[i].duration);
        
        // cout << "next: " << nextTime << " dest: " << destTime << endl;
        
        if (destTime > nextTime)
        {
            int finishedAmount = TimeDiff(nextTime, currentTime);
            times[i].duration -= finishedAmount;
            stack.push_back(times[i]);
            currentTime = nextTime;
            
            // cout << times[i].subject << " finished: " << finishedAmount << " left time: " << times[i].duration << endl;
            // cout << "current: " << currentTime << "\n\n";
            continue;
        }
        
        currentTime = destTime;
        answer.push_back(times[i].subject);
        
        // cout << "current: " << currentTime << endl;
        // cout << ">> finished: " << answer.back() << "\n\n";
        
        while (!stack.empty())
        {
            int result = CalcTime(currentTime, stack.back().duration);
            
            if (result > nextTime)
            {
                int finishedAmount = TimeDiff(nextTime, currentTime);
                stack.back().duration -= finishedAmount;
                break;
            }
            
            currentTime = result;
            answer.push_back(stack.back().subject);
            
            // cout << "current: " << currentTime << endl;
            // cout << ">> finished: " << answer.back() << "\n\n";
            
            stack.pop_back();
        }
        
        currentTime = nextTime;
    }
    
    while (!stack.empty())
    {
        answer.push_back(stack.back().subject);
        stack.pop_back();
    }
    
    return answer;
}