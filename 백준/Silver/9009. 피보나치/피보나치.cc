#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> fibo = {0, 1};
    for (int i = 2; i <= 45 ; i++)
        fibo.push_back(fibo[i - 1] + fibo[i - 2]);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> answers;
        for (int i = 45; i >= 1; i--) {
            if (fibo[i] <= n) {
                n -= fibo[i];
                answers.push_back(fibo[i]);
            }
        }
        int size = answers.size();

        for (int i = size - 1; i >= 0; i--)
            cout << answers[i] << " ";
        cout << '\n';
    }
    return 0;
}