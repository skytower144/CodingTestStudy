#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char op[3] = {' ', '+', '-'};

int Calculate(vector<char>& temp)
{
    vector<int> nums;
    vector<char> tempOp;

    string tempNum = "";

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] >= '0' && temp[i] <= '9')
            tempNum += temp[i];

        else if (temp[i] == ' ')
            continue;

        else if (temp[i] == '+' || temp[i] == '-')
        {
            if (tempNum != "")
                nums.push_back(stoi(tempNum));

            tempNum = "";
            tempOp.push_back(temp[i]);
        }
    }
    if (tempNum != "")
        nums.push_back(stoi(tempNum));

    int sum = nums[0];

    for (int i = 0; i < tempOp.size(); i++)
    {
        if (tempOp[i] == '+')
            sum += nums[i + 1];

        else if (tempOp[i] == '-')
            sum -= nums[i + 1];
    }
    return sum;

}

void GetComb(vector<char>& temp, char n, char c)
{
    if (c == n)
    {
        if (Calculate(temp) == 0)
        {
            for (int t = 0; t < temp.size(); t++)
                cout << temp[t];
            cout << '\n';
        }
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        temp.push_back(op[i]);
        temp.push_back((char)(c + 1));

        GetComb(temp, n, (char)(c + 1));

        temp.pop_back();
        temp.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<char> temp;
        temp.push_back('1');
        GetComb(temp, n + '0', '1');
        cout << '\n';
    }

    return 0;
}