#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<char>> grid;

int ReturnPow(int num) {
    int count = 0;
    while (num > 1) {
        num /= 2;
        count++;
    }
    return count;
}
void CreateTriangle(int size, pair<int, int> point) {
    pair<int, int> pointA, pointB, pointC;

    int height = 3 * pow(2, size);
    int x = point.first;
    int y = point.second;

    if (size == 0) {
        grid[y][x] = '*';
        grid[y + 1][x - 1] = grid[y + 1][x + 1] = '*', grid[y + 1][x] = '\0';

        for (int i = 0; i < 5; i++)
            grid[y + 2][x - 2 + i] = '*';
        return;
    }
    pointA = {x, y};
    pointB = {x - (height / 2), y + height / 2};
    pointC = {x + (height / 2), y + height / 2};
    
    CreateTriangle(size - 1, pointA);
    CreateTriangle(size - 1, pointB);
    CreateTriangle(size - 1, pointC);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
   
    grid = vector<vector<char>>(n, vector<char>(n * 2 - 1, '\0'));
    int k = ReturnPow(n / 3);
    CreateTriangle(k, {n - 1, 0});

    for (const auto& line : grid) {
        for (const auto& c : line) {
            if (c == '\0')
                cout << " ";
            else
                cout << c;
        }
        cout << '\n';
    }
    return 0;
}