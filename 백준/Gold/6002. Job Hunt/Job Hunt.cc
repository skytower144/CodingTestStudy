#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int D, P, C, F, S;

bool BelmanFord(vector<vector<int>>& paths, vector<int>& earned) {
    earned[S] = D;

    for (int i = 1; i <= C; i++) {
        for (const auto& path : paths) {
            int from = path[0];
            int to = path[1];
            int earn = path[2];

            if (earned[from] == INT_MIN)
                continue;
            
            if (earned[from] + earn > earned[to]) {
                earned[to] = earned[from] + earn;
                if (i == C)
                    return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> D >> P >> C >> F >> S;

    int p1, p2, cost;
    vector<vector<int>> paths;
    vector<int> earned(C + 1, INT_MIN);

    for (int i = 0; i < P; i++) {
        cin >> p1 >> p2;
        paths.push_back({p1, p2, D});
    }
    for (int i = 0; i < F; i++) {
        cin >> p1 >> p2 >> cost;
        paths.push_back({p1, p2, D - cost}); 
    }
    int answer = INT_MIN;
    if (BelmanFord(paths, earned)) {
        for (int i = 1; i <= C; i++)
            answer = max(answer, earned[i]);
    }
    else
        answer = -1;
    cout << answer;
    return 0;
}