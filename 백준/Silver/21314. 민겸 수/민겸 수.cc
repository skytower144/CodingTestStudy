#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>;

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    
    string num;
    cin >> num;

    string minNum = "";
    string maxNum = "";
    vector<char> maxStack;
    int minIndex = 0;

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == 'M')
        {
            maxStack.push_back('0');

            minNum += minIndex > 0 ? '0' : '1';
            minIndex++;
        }
        else
        {
            maxNum += '5';
            minNum += '5';
            minIndex = 0;

            while (!maxStack.empty())
            {
                maxNum += maxStack.back();
                maxStack.pop_back();
            }
        }
    }

    while (!maxStack.empty())
    {
        maxNum += '1';
        maxStack.pop_back();
    }

    cout << maxNum << '\n';
    cout << minNum << '\n';

    return 0;
}
