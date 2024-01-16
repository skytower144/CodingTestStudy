#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<char, int> broken;

bool CanMake(int num) {
    string temp = to_string(num);

    for (const auto& c : temp) {
        if (broken.count(c))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int current = 100;
    int minCount = abs(n - current);
    char brokenNum;

    for (int i = 0; i < m; i++) {
        cin >> brokenNum;
        broken[brokenNum]++;
    }
    for (int i = 0; i <= 1000000; i++) {
        if (!CanMake(i)) continue;
        int compare = abs(i - n) + to_string(i).size();
        minCount = min(minCount, compare);
    }
    cout << minCount;
    return 0;
}
