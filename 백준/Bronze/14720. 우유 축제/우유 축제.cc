#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int milkType;
    int nextDrink = 0;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        cin >> milkType;
        if (nextDrink == milkType) {
            answer++;
            nextDrink = (nextDrink + 1) % 3;
        }
    }
    cout << answer;
    return 0;
}