#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> bottles;
    while (n > 0) {
        for (int i = 1;  ; i++) {
            if (pow(2, i) > n) {
                n -= pow(2, i - 1);
                bottles.push_back(pow(2, i - 1));
                break;
            }
        }
    }
    int answer = 0;
    int totalBottles = bottles.size();
    while (totalBottles > 1 && totalBottles > k) {
        answer += bottles[totalBottles - 2] - bottles[totalBottles - 1];
        bottles[totalBottles - 2] *= 2;

        bottles.pop_back();
        totalBottles--;

        // for (auto b : bottles) cout << b << " ";
        // cout << endl;
    }
    cout << answer;
    return 0;
}