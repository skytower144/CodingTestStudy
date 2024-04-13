#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int n = phone_book.size();
    
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < n - 1; i++) {
        string current = phone_book[i];
        string compare = phone_book[i + 1].substr(0, current.size());

        if (compare == current)
            return false;
    }
    return answer;
}