#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int balls = 0;
    vector<int> basket(k, 0);
    for (int i = 0; i < k; i++) {
        if (i == k - 1)
            basket[i] = n - balls;
        else
            basket[i] = i + 1;
        balls += basket[i];
    }
    if (basket[k - 1] <= 0 || basket[k - 2] >= basket[k - 1])
        cout << -1;
    else {
        int index = k - 2;
        while (basket[k - 1] > basket[k - 2]) {
            if (index == k - 2 && basket[k - 1] - 1 <= basket[k - 2] + 1)
                break;
            else if (basket[k - 1] - 1 <= basket[k - 2])
                break;
            basket[index]++;
            basket[k - 1]--;
            index--;
            if (index == -1) index = k - 2;
        }
        cout << basket[k - 1] - basket[0];
    }
    return 0;   
}