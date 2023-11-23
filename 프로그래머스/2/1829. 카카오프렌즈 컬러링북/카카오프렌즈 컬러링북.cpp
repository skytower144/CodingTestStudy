#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int blockCount = 0;
    
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && !visited[i][j]) {
                int blockType = picture[i][j];
                visited[i][j] = 1;
                blockCount = 1;
                number_of_area++;
                
                queue<pair<int, int>> q;
                q.push(pair<int, int>(j, i));
                
                while (!q.empty()) {
                    pair<int, int> block = q.front();
                    int x = block.first;
                    int y = block.second;
                    q.pop();
                    
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && blockType == picture[ny][nx] && !visited[ny][nx]) {
                            pair<int, int> newBlock(nx, ny);
                            q.push(newBlock);
                            visited[ny][nx] = 1;
                            blockCount++;
                        }
                    }
                }
                if (max_size_of_one_area < blockCount)
                    max_size_of_one_area = blockCount;
            }
        }
    }
    return {number_of_area, max_size_of_one_area};
}