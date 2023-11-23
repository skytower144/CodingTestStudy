#include <vector>
#include <string>

using namespace std;

vector<vector<int>> marked;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
int height, width;

int CountArea(int x, int y, int number, vector<vector<int>> pic) {
    if (marked[y][x] || number == 0 || number != pic[y][x]) return 0;
    
    int nx, ny;
    int count = 1;
    marked[y][x] = 1;
    
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
            count += CountArea(nx, ny, number, pic);
        }
    }
    return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int areaCount = 0;
    
    marked = vector(m, vector<int>(n, 0));
    height = m, width = n;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!marked[i][j] && picture[i][j] != 0) {
                number_of_area++;
                areaCount = CountArea(j, i, picture[i][j], picture);
                
                if (max_size_of_one_area < areaCount)
                    max_size_of_one_area = areaCount;
            }
        }
    }
    return {number_of_area, max_size_of_one_area};
}