#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;

void BFS(vector<vector<int>>& maps, vector<vector<int>>& distance) {
    queue<pair<int, int>> q;
    distance[0][0] = 1;
    q.push({0, 0});
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
        
            if (maps[ny][nx] == 0)
                continue;
            
            if (distance[ny][nx] == 0) {
                distance[ny][nx] = distance[y][x] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    vector<vector<int>> distance(n, vector<int>(m, 0));
    
    BFS(maps, distance);
    answer = distance[n - 1][m - 1] ? distance[n - 1][m - 1] : -1;
    
    return answer;
}