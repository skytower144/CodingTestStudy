#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string sentence;
        getline(cin, sentence);

        stringstream ss(sentence);
        string word;

        while (ss >> word) {
            for (int i = word.size() - 1; i >= 0; i--)
                cout << word[i];
            cout << " ";
        }
        cout << '\n';
    }
}