#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> dna(n);
    for (int i = 0; i < n; i++) cin >> dna[i];
    
    string answer = "";
    int hammingDistance = 0;

    for (int j = 0; j < m; j++) {
        unordered_map<char, int> charCount;
        int maxCount = -1;
        char maxChar;

        for (int i = 0; i < n; i++) {
            charCount[dna[i][j]]++;
            if (maxCount < charCount[dna[i][j]] || (maxCount == charCount[dna[i][j]]) && maxChar > dna[i][j]) {
                maxCount = charCount[dna[i][j]];
                maxChar = dna[i][j];
            }
        }
        answer += maxChar;
        hammingDistance += n - maxCount;
    }
    cout << answer << '\n' << hammingDistance;
    return 0;
}