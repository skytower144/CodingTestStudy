#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int CalculateTime(string time)
{
    vector<int> timeInfo;
    int totalMinutes = 0;
    string temp = "";
    time += ':';
    
    for (char c : time)
    {
        if (c != ':')
            temp += c;
        else
        {
            timeInfo.push_back(stoi(temp));
            temp = "";
        }
    }
    return timeInfo[0] * 60 + timeInfo[1];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, int> record;
    map<string, int> feeMap;
    
    for (int i = 0; i < records.size(); i++)
    {
        const string& info = records[i];
        
        stringstream ss(info);
        string time, carNum, history;
        
        ss >> time >> carNum >> history;
        
        int minutes = CalculateTime(time);
        
        if (history == "IN")
            record[carNum] = minutes;
        
        else
        {
            feeMap[carNum] += (minutes - record[carNum]);
            record[carNum] = -1;
        }
    }
    for (auto& [k, v] : record)
    {
        if (v != -1)
        {
            feeMap[k] += (CalculateTime("23:59") - record[k]);
            record[k] = -1;
        }
    }
    for (auto& [k, v] : feeMap)
    {
        int totalFee = fees[1];
        if (v > fees[0])
            totalFee += ceil((double)(v - fees[0]) / fees[2]) * fees[3];
        
        answer.push_back(totalFee);
    }
    return answer;
}