#include <iostream>
#include <vector>
#include <string>

using namespace std;

void CreateMinMaxNum(string A, string& minA, string& maxA) {
    for (auto& a : A) {
        if (a == '5' || a == '6') {
            minA += '5';
            maxA += '6';
            continue;
        }
        minA += a;
        maxA += a;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string minA, maxA, minB, maxB;

    string A, B;
    cin >> A >> B;

    CreateMinMaxNum(A, minA, maxA);
    CreateMinMaxNum(B, minB, maxB);

    int minAnswer = stoi(minA) + stoi(minB);
    int maxAnswer = stoi(maxA) + stoi(maxB);

    cout << minAnswer << " " << maxAnswer;
    return 0;
}