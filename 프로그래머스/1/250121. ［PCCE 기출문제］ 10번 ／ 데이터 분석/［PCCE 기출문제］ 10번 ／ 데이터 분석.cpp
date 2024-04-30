#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx;

int GetIndex(string type) {
    if (type == "code")
        return 0;
    else if (type == "date")
        return 1;
    else if (type == "maximum")
        return 2;
    else
        return 3;
}
bool compare(vector<int>& a, vector<int>& b) {
    return a[idx] < b[idx];
}
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    idx = GetIndex(ext);
    
    for (int i = 0; i < data.size(); i++) {
        if (data[i][idx] < val_ext)
            answer.push_back(data[i]);
    }
    idx = GetIndex(sort_by);
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}