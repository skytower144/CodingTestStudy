#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<int> numbers;

void Backtrack(vector<int>& temp, vector<int>& visited, int count) {
    if (count == m) {
        for (const auto& num : temp)
            cout << num << " ";
        cout << '\n';
        return;
    }   
    int before = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] || before == numbers[i])
            continue;

        temp.push_back(numbers[i]);
        before = numbers[i];
        visited[i] = 1;
        Backtrack(temp, visited, count + 1);

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

    Backtrack(temp, visited, 0);

    return 0;
}