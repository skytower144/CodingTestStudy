#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int minX = wallpaper[0].size(), minY = wallpaper.size();
    int maxX = 0, maxY = 0;
    
    for (int y = 0; y < wallpaper.size(); y++) {
        for (int x = 0; x < wallpaper[0].size(); x++) {
            if (wallpaper[y][x] == '#') {
                if (minX > x) minX = x;
                if (minY > y) minY = y;
                if (maxX < x + 1) maxX = x + 1;
                if (maxY < y + 1) maxY = y + 1;
            }
        }
    }
    
    return {minY, minX, maxY, maxX};
}