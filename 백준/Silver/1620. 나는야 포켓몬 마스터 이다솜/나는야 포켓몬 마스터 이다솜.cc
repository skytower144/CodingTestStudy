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

    unordered_map<string, int> pokedex;
    vector<string> pokemons(n + 1, "");
    string userInput;

    for (int i = 1; i <= n; i++) {
        cin >> pokemons[i];
        pokedex[pokemons[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> userInput;

        if (pokedex.count(userInput))
            cout << pokedex[userInput] << '\n';
        else
            cout << pokemons[stoi(userInput)] << '\n';
    }
    return 0;
}