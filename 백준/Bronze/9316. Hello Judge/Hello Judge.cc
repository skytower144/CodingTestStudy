#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    string sentence = "Hello World, Judge ";

    for (int i = 0; i < n; i++)
        cout << sentence << i + 1 << '!' << '\n';

    return 0;
}   