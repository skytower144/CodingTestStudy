#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int k = 1;
    int answer = 0;

    while (n > 0) {
        if (n >= k) {
            n -= k;
            k++;
            answer++;
        }
        else
            k = 1;
    }
    cout << answer;
    return 0;
}