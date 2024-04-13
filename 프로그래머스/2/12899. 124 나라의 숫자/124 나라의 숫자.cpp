#include <string>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// https://school.programmers.co.kr/questions/13704
// https://school.programmers.co.kr/questions/19755

string solution(int n) {
    string answer = "";
    
    while (n) {
        int left = n % 3;
        int quotient = n / 3;
        if (left == 0) {
            quotient--;
            left = 4;
        }
        n = quotient;
        answer = char(left + '0') + answer;
    }
    return answer;
}