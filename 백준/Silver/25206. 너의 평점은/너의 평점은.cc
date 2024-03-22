#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string courseName, grade;
    double credit;

    double totalSum = 0;
    double totalCredit = 0;

    unordered_map<string, double> gradeMap = {
        {"A+", 4.5}, {"A0", 4.0},
        {"B+", 3.5}, {"B0", 3.0},
        {"C+", 2.5}, {"C0", 2.0},
        {"D+", 1.5}, {"D0", 1.0},
        {"F", 0.0}
    };
    int repeat = 20;

    while (repeat--) {
        cin >> courseName >> credit >> grade;

        if (grade == "P")
            continue;

        totalCredit += credit;
        totalSum += credit * gradeMap[grade];
    }
    double answer = totalSum / totalCredit;
    cout << answer;

    return 0;
}