#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string sentence, explode;
    cin >> sentence >> explode;

    int sentSize = sentence.size();
    int explSize = explode.size();
    string current = "";

    for (int i = 0; i < sentSize; i++) {
        current += sentence[i];

        if (i < explSize - 1)
            continue;
        
        bool isExplode = true;
        int currentSize = current.size();

        for (int j = currentSize - explSize, k = 0; j < currentSize; j++, k++) {
            if (current[j] != explode[k]) {
                isExplode = false;
                break;
            }
        } 
        if (isExplode) {
            for (int j = 0; j < explSize; j++)
                current.pop_back();
        }
    }
    if (current == "")
        cout << "FRULA";
    else
        cout << current;

    return 0;
}