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

    string input = "";
    vector<string> channels(n);

    for (int i = 0; i < n; i++)
        cin >> channels[i];

    int cursor = 0;

    while (channels[cursor] != "KBS1")
    {
        input += '1';
        cursor++;
    }

    for (int i = 0; i < cursor; i++)
    {
        input += '4';
        swap(channels[cursor - i], channels[cursor - i - 1]);
    }

    cursor = 0;
    while (channels[cursor] != "KBS2")
    {
        input += '1';
        cursor++;
    }

    for (int i = 0; i < cursor - 1; i++)
        input += '4';

    cout << input;

    return 0;
}