#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    string name;
    int age, weight;

    while (true)
    {
        cin >> name >> age >> weight;

        if (name[0] == '#')
            break;

        cout << name;

        if (age > 17 || weight >= 80)
            cout << " Senior\n";
        else
            cout << " Junior\n";
    }
    return 0;
}