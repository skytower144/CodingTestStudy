#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    string s;
    int answer = 0;

    cin >> n >> s;

    while (n--)
    {
        string a;
        int k;

        cin >> a >> k;

        stringstream ss(a);
        string word;
        char split = '_';

        while (getline(ss, word, split))
        {
            if (word == s)
            {
                answer += k;
                break;
            }
        }
    }

    cout << answer;
    return 0;
}