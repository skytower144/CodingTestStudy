#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1;
    int idx = 0;
    int weightSum = 0;
    vector<pair<int, int>> tick;
    
    tick.push_back({truck_weights[idx], 1});
    weightSum += truck_weights[idx];
    idx++;
    
    while (!tick.empty()) {
        time++;
        
        for (int i = tick.size() - 1; i >= 0; i--) {
            tick[i].second++;
            
            if (tick[i].second > bridge_length) {
                weightSum -= tick[i].first;
                tick.erase(tick.begin() + i);
            }
        }
        if (idx < truck_weights.size() && weightSum + truck_weights[idx] <= weight) {
            tick.push_back({truck_weights[idx], 1});
            weightSum += truck_weights[idx];
            idx++;
        }
    }
    return time;
}