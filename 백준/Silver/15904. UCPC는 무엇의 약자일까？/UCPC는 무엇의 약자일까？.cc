#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string userInput;
    getline(cin, userInput);

    string answer = "hate";
    string abrv = "";
    char sequence[] = {'U', 'C', 'P', 'C'};
    int idx = 0;

    for (const auto c : userInput) {
        if (c == sequence[idx]) {
            abrv += sequence[idx];
            idx++;
            if (idx == 4) break;
        }
    }
    if (idx == 4) answer = "love";
    cout << "I " << answer << " UCPC";
    return 0;
}