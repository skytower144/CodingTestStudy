#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> puddle;
    int startPos, endPos;

    for (int i = 0; i < n; i++) {
        cin >> startPos >> endPos;
        puddle.push_back({startPos, endPos});
    }
    sort(puddle.begin(), puddle.end());
    int answer = 0;
    int lastCovered = -1;

    for (const auto& [s, e] : puddle) {
        if (lastCovered >= s && lastCovered >= e - 1)
            continue;
        
        else if (lastCovered >= s && lastCovered < e - 1)
            startPos = lastCovered + 1;
        
        else if (lastCovered < s)
            startPos = s;

        int plank = ceil((e - startPos) / (double)l);
        lastCovered = plank * l + startPos - 1;
        answer += plank;
    }
    cout << answer;
    return 0;
}