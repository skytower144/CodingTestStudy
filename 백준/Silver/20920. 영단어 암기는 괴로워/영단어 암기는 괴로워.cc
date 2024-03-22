#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct WordInfo
{
    int count;
    string word;

};
typedef struct WordInfo WordInfo;

bool compare(WordInfo &a, WordInfo &b) {
    if (a.count != b.count)
        return a.count > b.count;
    
    if (a.word.size() != b.word.size())
        return a.word.size() > b.word.size();
    
    return a.word < b.word;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

int n, m;
    string word;
    unordered_map<string, int> wordDict;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> word;
        if (word.size() >= m)
            wordDict[word]++;
    }
    vector<WordInfo> words;
    for (const auto [word, count] : wordDict)
        words.push_back({count, word});

    sort(words.begin(), words.end(), compare);

    for (int i = 0; i < words.size(); i++)
        cout << words[i].word << '\n';

    return 0;
}