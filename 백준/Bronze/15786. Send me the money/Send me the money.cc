#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    string memory;
    cin >> memory;

    for (int i = 0; i < m; i++)
    {
        string postit;
        cin >> postit;

        int idx = 0;
        bool isPossible = false;

        for (int j = 0; j < postit.size(); j++)
        {
            if (memory[idx] == postit[j])
            {
                idx++;

                if (idx == n)
                {
                    isPossible = true;
                    break;
                }
            }
        }

        if (isPossible)
            cout << "true\n";
        else
            cout << "false\n";
    }

    return 0;
}