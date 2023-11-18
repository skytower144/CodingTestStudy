#include <string>
#include <vector>

using namespace std;

bool IsCompareSmaller(string c, string p, int size) {
    for (int i = 0; i < size; i++) {
        if (c[i] > p[i]) return false;
        else if (c[i] < p[i]) return true;
    }
    return true;
}

int solution(string t, string p) {
    int answer = 0, tSize = t.size(), pSize = p.size();
    string compare;

    for (int i = 0; i <= tSize - pSize; i++) {
        compare = t.substr(i, pSize);
        if (IsCompareSmaller(compare, p, pSize)) answer++;
    }
    return answer;
}