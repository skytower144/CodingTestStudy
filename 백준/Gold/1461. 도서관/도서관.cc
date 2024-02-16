#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> books(n, 0);
    for (int i = 0; i < n; i++)
        cin >> books[i];
    
    books.push_back(0);
    sort(books.begin(), books.end());

    int pivot;
    int sum = 0;

    for (int i = 0; i <= n; i++) {
        if (books[i] == 0) {
            pivot = i;
            break;
        }
    }
    for (int i = 0; i < pivot; i += m)
        sum += abs(books[i]) * 2;
    
    for (int i = n; i > pivot; i -= m)
        sum += books[i] * 2;

    sum -= max(abs(books[0]), abs(books[n]));
    cout << sum;
    return 0;
}
