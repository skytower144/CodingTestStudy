#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int totalHouse = 0;
int totalChicken = 0;
int answer = 2500;

void CalculateDistance(vector<vector<int>>& distance, vector<int>& temp) {
    int distanceSum = 0;

    for (int i = 0; i < totalHouse; i++) {
        int length = 2500;

        for (const auto& idx : temp)
            length = min(length, distance[idx][i]);
        distanceSum += length;
    }
    answer = min(answer, distanceSum);
}

void Backtrack(vector<vector<int>>& distance, vector<int>& temp, int idx) {
    if (temp.size() == m) {
        CalculateDistance(distance, temp);
        return;
    }
    for (int i = idx; i < totalChicken; i++) {
        temp.push_back(i);
        Backtrack(distance, temp, i + 1);
        temp.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<pair<int, int>> chickenPos;
    vector<pair<int, int>> housePos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                totalChicken++;
                chickenPos.push_back({j, i});
            }
            else if (grid[i][j] == 1) {
                totalHouse++;
                housePos.push_back({j, i});
            }
        }
    }
    vector<vector<int>> distance(totalChicken, vector<int>(totalHouse, 0));
    vector<int> temp;

    for (int i = 0; i < totalChicken; i++) {
        for (int j = 0; j < totalHouse; j++)
            distance[i][j] = abs(housePos[j].first - chickenPos[i].first) + abs(housePos[j].second - chickenPos[i].second);
    }
    Backtrack(distance, temp, 0);
    cout << answer;
    return 0;
}