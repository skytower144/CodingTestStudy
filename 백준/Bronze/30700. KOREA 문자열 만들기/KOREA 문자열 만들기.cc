#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    
    string s;
    cin >> s;

    char kor[] = { 'K', 'O', 'R', 'E', 'A' };
    int idx = 0;
    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == kor[idx])
        {
            answer++;
            idx = (idx + 1) % 5;
        }
    }

    cout << answer;

    return 0;
}