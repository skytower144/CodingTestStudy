#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int n, m;
vector<int> numbers;
vector<int> temp;

void Combination(int count, vector<int>& visited) {
    if (count == m) {
        for (const auto t : temp)
            cout << t << " ";
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            temp.push_back(numbers[i]);
            visited[i] = 1;
            Combination(count + 1, visited);

            visited[i] = 0;
            temp.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    numbers = vector<int>(n, 0);
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) cin >> numbers[i];

    sort(numbers.begin(), numbers.end());
    Combination(0, visited);
    
    return 0;
}