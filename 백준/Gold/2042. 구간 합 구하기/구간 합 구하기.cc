#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<long long> arr;
vector<long long> tree;

long long GetSum(long long index) {
    long long sum = 0;
    
    while (index > 0) {
        sum += tree[index];
        index -= (index & -index);
    }
    return sum;
}
void UpdateTree(long long index, long long change) {
    long long diff = change - arr[index];
    arr[index] = change;

    while (index <= n) {
        tree[index] += diff;
        index += (index & -index);
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m >> k;

    long long a, b, c, num;
    arr = vector<long long>(n + 1, 0);
    tree = vector<long long>(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> num;
        UpdateTree(i, num);
    }
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;

        if (a == 1)
            UpdateTree(b, c);

        else if (a == 2)
            cout << (GetSum(c) - GetSum(b - 1)) << '\n';
    }
    return 0;
}