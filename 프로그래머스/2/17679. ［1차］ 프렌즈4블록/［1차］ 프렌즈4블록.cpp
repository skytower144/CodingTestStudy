#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> eraseTarget;
vector<vector<char>> Board;
int dx[] = {0, 1, 1, 0};
int dy[] = {0, 0, 1, 1};
int M, N;

void DebugBoard(int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << eraseTarget[i][j] << " ";
        cout << endl;
    }
}
vector<pair<int, int>> CheckTarget(int x, int y) {
    int nx, ny;
    vector<pair<int, int>> empty;
    vector<pair<int, int>> cords;
    
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            return empty;
        
        if (Board[ny][nx] == ' ')
            return empty;
        
        if (Board[y][x] != Board[ny][nx])
            return empty;
    
        cords.push_back({nx, ny});
    }
    return cords;
}
void Push(int x) {
    for (int y = M - 2; y >= 0; y--) {
        for (int v = y; v <= M - 2; v++) {
            if (Board[v + 1][x] == ' ') {
                Board[v + 1][x] = Board[v][x];
                Board[v][x] = ' ';
            }
        }
    }
}
int solution(int m, int n, vector<string> board) {
    Board = vector<vector<char>>(m, vector<char>(n, ' '));
    int answer = 0;
    M = m;
    N = n;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            Board[i][j] = board[i][j];
    }
    while (true) {
        int totalErase = 0;
        eraseTarget = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<pair<int, int>> block = CheckTarget(j, i);
                
                if (block.size() != 4)
                    continue;
                
                for (const auto& [x, y] : block) {
                    if (eraseTarget[y][x]) continue;
                    eraseTarget[y][x] = 1;
                    totalErase++;
                }
            }
        }
        if (totalErase == 0) break;
        answer += totalErase;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (eraseTarget[i][j])
                    Board[i][j] = ' ';
            }
        }
        for (int j = 0; j < n; j++) {
            Push(j);
        }
    }
    return answer;
}