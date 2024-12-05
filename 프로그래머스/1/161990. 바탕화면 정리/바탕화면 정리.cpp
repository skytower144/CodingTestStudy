#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int width = wallpaper[0].size();
    int height = wallpaper.size();
    
    int minX = width - 1;
    int minY = height - 1;
    int maxX = 0;
    int maxY = 0;
    
    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[0].size(); j++)
        {
            if (wallpaper[i][j] == '.')
                continue;
            
            minY = min(minY, i);
            minX = min(minX, j);
            
            maxY = max(maxY, i);
            maxX = max(maxX, j);
        }
    }
    return {minY, minX, maxY + 1, maxX + 1};
}