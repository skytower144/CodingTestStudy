#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int maxNumber = -1;

void GetMaxNumber(vector<vector<int>> board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            maxNumber = max(maxNumber, board[i][j]);
    }
}

void Move(int count, vector<vector<int>> board) {
    if (count == 5) {
        GetMaxNumber(board);
        return;
    }
    vector<vector<int>> copied = board;

    // UP
    for (int i = 0; i < n; i++) {
        bool merged[n] = {0, };
        
        for (int j = 1; j < n; j++) {
            bool isMerged = false;
            int k;

            for (k = j; k > 0; k--) {
                if (board[k][i] == 0)
                    break;

                if (board[k - 1][i] == 0) {
                    board[k - 1][i] = board[k][i];
                    board[k][i] = 0;
                }
                else if (!isMerged && !merged[k - 1] && board[k - 1][i] == board[k][i]) {
                    board[k - 1][i] += board[k][i];
                    board[k][i] = 0;
                    isMerged = true;
                }
                else
                    break;
            }
            if (isMerged)
                merged[k] = true;
        }
    }
    Move(count + 1, board);
    board = copied;

    // DOWN
    for (int i = 0; i < n; i++) {
        bool merged[n] = {0, };

        for (int j = n - 2; j >= 0; j--) {
            bool isMerged = false;
            int k;

            for (k = j; k <= n - 2; k++) {
                if (board[k][i] == 0)
                    break;

                if (board[k + 1][i] == 0) {
                    board[k + 1][i] = board[k][i];
                    board[k][i] = 0;
                }
                else if (!isMerged && !merged[k + 1] && board[k + 1][i] == board[k][i]) {
                    board[k + 1][i] += board[k][i];
                    board[k][i] = 0;
                    isMerged = true;
                }
                else
                    break;
            }
            if (isMerged)
                merged[k] = true;
        }
    }
    Move(count + 1, board);
    board = copied;

    // LEFT
    for (int i = 0; i < n; i++) {
        bool merged[n] = {0, };

        for (int j = 1; j < n; j++) {
            bool isMerged = false;
            int k;

            for (k = j; k > 0; k--) {
                if (board[i][k] == 0)
                    break;

                if (board[i][k - 1] == 0) {
                    board[i][k - 1] = board[i][k];
                    board[i][k] = 0;
                }
                else if (!isMerged && !merged[k - 1] && board[i][k - 1] == board[i][k]) {
                    board[i][k - 1] += board[i][k];
                    board[i][k] = 0;
                    isMerged = true;
                }
                else
                    break;
            }
            if (isMerged)
                merged[k] = true;
        }
    }
    Move(count + 1, board);
    board = copied;

    // RIGHT
    for (int i = 0; i < n; i++) {
        bool merged[n] = {0, };

        for (int j = n - 2; j >= 0; j--) {
            bool isMerged = false;
            int k;

            for (k = j; k <= n - 2; k++) {
                if (board[i][k] == 0)
                    break;

                if (board[i][k + 1] == 0) {
                    board[i][k + 1] = board[i][k];
                    board[i][k] = 0;
                }
                else if (!isMerged && !merged[k + 1] && board[i][k + 1] == board[i][k]) {
                    board[i][k + 1] += board[i][k];
                    board[i][k] = 0;
                    isMerged = true;
                }
                else
                    break;
            }
            if (isMerged)
                merged[k] = true;
        }
    }
    Move(count + 1, board);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    int number;

    vector<vector<int>> board(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> number;
            board[i].push_back(number);
        }
    }
    Move(0, board);

    // cout << endl;
    // for (auto line : board) {
    //     for (auto l : line)
    //         cout << l << " ";
    //     cout << endl;
    // }

    cout << maxNumber;
    return 0;
}