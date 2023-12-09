#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string name;
    string answer = "";
    string middle = "";
    string frontPart = "";
    int nameSize = 0;
    int strikes = 0;
    map<char, int> charMap;

    cin >> name;
    for (const auto c : name) {
        charMap[c]++;
        nameSize++;
    }
    for (const auto [character, count] : charMap) {
        if (count % 2) {
            strikes++;
            middle += character;
        }
        if ((count % 2 && nameSize % 2 == 0) || strikes > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
        answer += string(count / 2, character);
        charMap[character] -= (count / 2) * 2;
    }
    frontPart = answer;
    reverse(answer.begin(), answer.end());
    answer = frontPart + middle + answer;
    
    cout << answer;
    return 0;
}
