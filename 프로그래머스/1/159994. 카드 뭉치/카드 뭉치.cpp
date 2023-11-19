#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int front1 = 0, front2 = 0;
    
    for (auto g : goal) {
        if (cards1[front1] == g) front1++;
        else if (cards2[front2] == g) front2++;
        else return "No";
    }
    return "Yes";
}