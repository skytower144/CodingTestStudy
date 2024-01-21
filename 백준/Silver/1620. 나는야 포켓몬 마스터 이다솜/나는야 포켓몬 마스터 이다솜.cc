#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> pokedex1, pokedex2;
    string pokemon, userInput;

    for (int i = 1; i <= n; i++) {
        cin >> pokemon;
        pokedex1[to_string(i)] = pokemon;
        pokedex2[pokemon] = to_string(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> userInput;

        if (pokedex1.count(userInput))
            cout << pokedex1[userInput] << '\n';
        else
            cout << pokedex2[userInput] << '\n';
    }
    return 0;
}