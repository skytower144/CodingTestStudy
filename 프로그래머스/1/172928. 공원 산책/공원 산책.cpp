#include <string>
#include <vector>
#include <map>

using namespace std;

int width, height, cur_x, cur_y;

bool CanGo(vector<string> park, int distance, int x_dir, int y_dir, int nx, int ny) {
    int temp_x = cur_x, temp_y = cur_y;
    
    if (nx < 0 || nx >= width || ny < 0 || ny >= height)
        return false;
    
    for (int i = 0; i < distance; i++) {
        temp_x += x_dir;
        temp_y += y_dir;
        
        if (park[temp_y][temp_x] == 'X')
            return false;
    }
    return true;
}

void SetStartingPoint(vector<string> park) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (park[i][j] == 'S') {
                cur_x = j, cur_y = i;
                return;
            }
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    map<char, int> dirMap = {{'N', 0}, {'S', 1}, {'W', 2}, {'E', 3}};
    int distance, x_dir, y_dir, nx, ny;
    
    height = park.size();
    width = park[0].size();
    SetStartingPoint(park);

    for (auto route : routes) {
        distance = route[2] - '0';
        
        x_dir = dx[dirMap[route[0]]];
        y_dir = dy[dirMap[route[0]]];
        
        nx = cur_x + x_dir * distance;
        ny = cur_y + y_dir * distance;
        
        if (CanGo(park, distance, x_dir, y_dir, nx, ny))
            cur_x = nx, cur_y = ny;
    }
    return {cur_y, cur_x};
}