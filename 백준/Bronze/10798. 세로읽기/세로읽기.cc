#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    vector<vector<char>> board(5, vector<char>(15, '\0'));
    string word;

    for (int i = 0; i < 5; i++) {
        cin >> word;
        int wordSize = word.size();
        
        for (int j = 0; j < wordSize; j++)
            board[i][j] = word[j];
    }
    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 5; i++) {
            if (board[i][j] == '\0')
                continue;

            cout << board[i][j];
        }
    }
    return 0;
}