#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    bool isWhite = true;
    string line;
    char block;
    int answer = 0;

    for (int i = 0; i < 8; i++) {
        cin >> line;
        for (const auto& block : line) {
            if (block == 'F' && isWhite)
                answer++;
            
            isWhite = !isWhite;
        }
        isWhite = !isWhite;
    }
    cout << answer;

    return 0;
}