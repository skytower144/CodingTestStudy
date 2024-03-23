#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> fieldInfo;

bool IsBlankField(int i) {
    int s1 = i;
    int s2 = (i + 1) % 6;
    int s3 = (i + 2) % 6;
    int s4 = (i + 3) % 6;

    if (fieldInfo[s1].first != fieldInfo[s3].first)
        return false;
    
    if ((fieldInfo[s2].first * fieldInfo[s4].first) != 12 && (fieldInfo[s2].first * fieldInfo[s4].first) != 2)
        return false;
    
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int k;
    cin >> k;

    int longestWidth = -1;
    int longestHeight = -1;

    int direction, length;
    int blankSize = -1;

    for (int i = 0; i < 6; i++) {
        cin >> direction >> length;
        fieldInfo.push_back({direction, length});
    }
    for (int i = 0; i < 6; i++) {
        if (blankSize == -1 && IsBlankField(i))
            blankSize = fieldInfo[i].second * fieldInfo[(i + 1)  % 6].second;
        
        direction = fieldInfo[i].first;
        length = fieldInfo[i].second;
        
        if (direction == 1 || direction == 2)
            longestWidth = max(longestWidth, length);

        else if (direction == 3 || direction == 4)
            longestHeight = max(longestHeight, length);
    }
    int answer = k * (longestWidth * longestHeight - blankSize);
    cout << answer;
    return 0;
}