#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

struct wordInfo
{
    int count;
    int length;
    string word;
};
typedef struct wordInfo wordInfo;

struct compare
{
    bool operator()(wordInfo &a, wordInfo &b) {
        if (a.count != b.count)
            return a.count < b.count;
        
        if (a.length != b.length)
            return a.length < b.length;
        
        return a.word > b.word;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    string word;
    unordered_map<string, int> wordDict;
    priority_queue<wordInfo, vector<wordInfo>, compare> pq;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> word;
        if (word.size() >= m)
            wordDict[word]++;
    }
    for (const auto& [word, count] : wordDict) {
        int wordSize = word.size();
        wordInfo info = {count, wordSize, word};
        pq.push(info);
    }
    int pqSize = pq.size();
    for (int i = 0; i < pqSize; i++) {
        cout << pq.top().word << '\n';
        pq.pop();
    }
    return 0;
}