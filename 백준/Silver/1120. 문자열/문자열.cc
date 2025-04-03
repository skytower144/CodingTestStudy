#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    string a, b;
    cin >> a >> b;

    int diff = b.size() - a.size();
    int answer = b.size();

    for (int i = 0; i <= diff; i++)
    {
        int sum = 0;

        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] != b[i + j])
                ++sum;
        }

        answer = min(answer, sum);
    }

    cout << answer;
    return 0;
}