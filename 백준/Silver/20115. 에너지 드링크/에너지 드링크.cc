#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<double> drinks(n, 0);
    for (int i = 0; i < n; i++)
        cin >> drinks[i];
    
    sort(drinks.begin(), drinks.end(), greater());
    double answer = drinks[0];

    for (int i = 1; i < n; i++) {
        answer += drinks[i] / 2.0;
    }
    cout << answer;
    return 0;
}