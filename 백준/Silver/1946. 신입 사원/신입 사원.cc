#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n;
    vector<int> answers;
    cin >> t;

    for (int i = 0; i < t; i++) {
        vector<pair<int, int>> candidates;
        cin >> n;

        for (int j = 0; j < n; j++) {
            pair<int, int> grade;
            cin >> grade.first >> grade.second;
            candidates.push_back(grade);
        }
        sort(candidates.begin(), candidates.end());

        int min = candidates[0].second;
        int count = 1;

        for (int j = 1; j < n; j++) {
            if (candidates[j].second < min) {
                count++;
                min = candidates[j].second;
            }
        }
        answers.push_back(count);
    }
    for (auto a : answers) cout << a << endl;
    return 0;
}