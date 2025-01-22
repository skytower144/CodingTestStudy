#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    while (true)
    {
        char c;
        string sentence;
        cin >> c;

        if (c == '#')
            break;

        getline(cin, sentence);
        sentence = sentence.substr(1);

        int count = 0;

        for (int i = 0; i < sentence.size(); i++)
        {
            char t = sentence[i];

            if (t >= 'A' && t <= 'Z')
                t += 'a' - 'A';

            if (t == c)
                count++;
        }

        cout << c << " " << count << '\n';
    }

    return 0;
}