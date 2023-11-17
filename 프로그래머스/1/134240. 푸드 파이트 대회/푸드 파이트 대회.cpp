#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string first = "", second = "";
    for (int i = 1; i < food.size(); i++) {
        if (food[i] % 2) food[i]--;
        first += string(food[i] / 2, '0' + i);
    }
    second = first;
    reverse(second.begin(), second.end());
    return first + '0' + second;
}