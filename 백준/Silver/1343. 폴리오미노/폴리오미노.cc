#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string answer = "";
    string board;
    int xSize = 0;
    cin >> board;

    int boardSize = board.size();
    for (int i = 0; i < boardSize; i++) {
        if (board[i] == 'X') xSize++;
        if ((board[i] == '.' && xSize > 0) || i == boardSize - 1) {
            if ((xSize % 4) % 2) {
                cout << -1;
                return 0;
            }
            answer += string(xSize / 4 * 4, 'A');
            answer += string(xSize % 4, 'B');
            xSize = 0;
        }
        if (board[i] == '.') answer += '.';
    }
    cout << answer;
    return 0;
}
