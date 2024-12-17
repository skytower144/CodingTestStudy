#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

char Convert(string num)
{
    int sum = 0;
    int idx = 0;

    while (idx < num.size())
    {
        sum += (num[idx] - '0') * pow(2, idx);
        idx++;
    }

    return char(sum + '0');
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    string answer = "";

    string num;
    cin >> num;

    string cut = "";

    while (!num.empty())
    {
        cut.push_back(num.back());
        num.pop_back();

        if (cut.size() == 3)
        {
            answer.push_back(Convert(cut));
            cut.clear();
        }
    }
    
    if (!cut.empty())
        answer.push_back(Convert(cut));

    for (int i = answer.size() - 1; i >= 0; i--)
        cout << answer[i];

    return 0;
}