#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string document, word;
    getline(cin, document);
    getline(cin, word);

    int wordIdx = 0;
    int wordSize = word.size();
    int documentSize = document.size();
    int answer = 0;

    while (wordIdx < documentSize) {
        auto n = document.find(word, wordIdx);

        if (n == string::npos)
            break;
        
        answer++;
        wordIdx = n + wordSize;
    }
    cout << answer;
    return 0;
}