#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n, 0));
    int horizontal = 0;
    int vertical = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == '.')
                count++;

            else if (grid[i][j] == 'X') {
                if (count >= 2) horizontal++;
                count = 0;
            }
        }
        if (count >= 2) horizontal++;
        count = 0;
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == '.')
                count++;

            else if (grid[i][j] == 'X') {
                if (count >= 2) vertical++;
                count = 0;
            }
        }
        if (count >= 2) vertical++;
        count = 0;
    }
    cout << horizontal << " " << vertical; 
    return 0;
}