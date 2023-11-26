#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, wordSize;
    int answer = 0;
    int startNum = 9;

    string word;
    vector<int> charCount(26, 0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> word;
        wordSize = word.size();
        for (int j = 0; j < wordSize; j++)
            charCount[word[j] - 'A'] += pow(10, wordSize - j - 1);
    }
    sort(charCount.begin(), charCount.end(), greater());

    for (auto count : charCount) {
        if (!count) continue;
        answer += count * startNum--;
    }
    cout << answer;
    return 0;
}