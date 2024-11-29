#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare1(pair<int, int>& a, pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second < b.second; 
    return a.first > b.first;
}

bool compare2(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> songMap;
    
    vector<pair<string, int>> totalPlays;
    
    for (int i = 0; i < genres.size(); i++)
        songMap[genres[i]].push_back({plays[i], i});

    for (const auto& [k, v] : songMap)
    {
        int playCount = 0;
        for (pair<int, int> p : v)
            playCount += p.first;
        
        totalPlays.push_back({k, playCount});
    }
    
    sort(totalPlays.begin(), totalPlays.end(), compare2);
    
    for (int i = 0; i < songMap.size(); i++)
    {
        vector<pair<int, int>> songs = songMap[totalPlays[i].first];
        sort(songs.begin(), songs.end(), compare1);
        
        int maxJ = min(2, (int)songs.size());
        
        for (int j = 0; j < maxJ; j++)
            answer.push_back(songs[j].second);
    }
    return answer;
}