#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0, tSize = t.size(), pSize = p.size();

    for (int i = 0; i <= tSize - pSize; i++)
        if (t.substr(i, pSize) <= p) answer++;
    return answer;
}