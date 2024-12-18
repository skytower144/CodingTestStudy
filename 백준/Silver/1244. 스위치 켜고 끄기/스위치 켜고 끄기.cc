#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, s, k;
vector<bool> switches;

void Print()
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && i % 20 == 0)
            cout << '\n';

        cout << switches[i] << " ";
    }
}

void MaleFlip(int num)
{
    for (int i = 1; i * num - 1 < n; i++)
        switches[i * num - 1] = !switches[i * num - 1];
}

void FemaleFlip(int num)
{
    num -= 1;
    int left = num - 1;
    int right = num + 1;

    switches[num] = !switches[num];

    while (left >= 0 && right < n && switches[left] == switches[right])
    {
        switches[left] = !switches[left];
        switches[right] = !switches[right];
        left--;
        right++;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    bool isOn;

    for (int i = 0; i < n; i++)
    {
        cin >> isOn;
        switches.push_back(isOn);
    }

    cin >> m;

    while (m--)
    {
        cin >> s >> k;

        if (s == 1)
            MaleFlip(k);
        else
            FemaleFlip(k);

    }

    Print();
    return 0;
}