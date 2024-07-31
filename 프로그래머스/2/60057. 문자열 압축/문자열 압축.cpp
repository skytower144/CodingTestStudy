#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int sLen = s.size();
    int answer = sLen;
    
    for (int unitLen = 1; unitLen < sLen; unitLen++)
    {
        vector<int> zipCount(1, 0);
        int totalUnits = sLen / unitLen;
        int extraUnit = sLen % unitLen;
        
        for (int j = unitLen; j < sLen; j += unitLen)
        {
            string left = s.substr(j - unitLen, unitLen);
            string right = s.substr(j, unitLen);
            
            if (left == right)
            {
                totalUnits--;
                zipCount[zipCount.size() - 1]++;
            }
            else zipCount.push_back(0);
        }
        int currentZipLength = totalUnits * unitLen + extraUnit;

        for (const auto& count : zipCount)
        {
            if (count == 0) continue;
            currentZipLength += to_string(count + 1).size();
        }
        answer = min(answer, currentZipLength);
    }
    return answer;
}