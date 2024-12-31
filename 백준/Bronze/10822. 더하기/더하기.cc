#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;

    stringstream ss(s);
    string token;

    long long answer = 0;

    while (getline(ss, token, ','))
        answer += stoll(token);

    cout << answer;
    // cout << "HAPPY NEW YEAR!" << endl;
    return 0;
}