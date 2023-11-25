#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 30의 배수는 모든 자리의 숫자의 합이 3의 배수, 마지막 숫자가 0이다. 

    int total = 0;
    string n;
    string answer = "";

    cin >> n;
    sort(n.begin(), n.end(), greater());
    
    for (auto c : n) total += c - '0';
    answer = (total % 3 || n.back() != '0') ? "-1" : n;
    
    cout << answer;
    return 0;
}