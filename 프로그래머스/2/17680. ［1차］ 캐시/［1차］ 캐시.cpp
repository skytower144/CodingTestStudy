#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    const int HIT = 1;
    const int MISS = 5;
    
    unordered_map<string, int> cacheMap;
    vector<string> q;
    
    for (auto city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        if (!cacheMap.count(city)) {
            answer += MISS;
            
            if (cacheSize == 0)
                continue;
            
            if (cacheMap.size() == cacheSize) {
                cacheMap.erase(q[0]);
                q.erase(q.begin() + 0);
            }
            q.push_back(city);
            cacheMap[city]++;
        }
        else {
            answer += HIT;
            
            for (int i = 0; i < q.size(); i++) {
                if (q[i] == city) {
                    q.erase(q.begin() + i);
                    break;
                }
            }
            q.push_back(city);
        }
    }
    return answer;
}