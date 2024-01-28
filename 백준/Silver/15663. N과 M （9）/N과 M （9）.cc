#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>

using namespace std;

int n, m;
vector<int> numbers;
unordered_map<string, int> numMap;

void Backtrack(vector<int>& temp, vector<int>& visited, string tag) {
    if (temp.size() == m) {
        if (numMap.count(tag))
            return;
        
        numMap[tag]++;
        for (const auto& num : temp)
            cout << num << " ";
        cout << '\n';
        return;
    }   

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        string add = '.' + to_string(numbers[i]);
        temp.push_back(numbers[i]);
        visited[i] = 1;
        Backtrack(temp, visited, tag + add);

        temp.pop_back();
        visited[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    int num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());

    vector<int> temp;
    vector<int> visited(n, 0);
    string tag = "";
    Backtrack(temp, visited, tag);

    return 0;
}