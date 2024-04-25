#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int counter[10000000];

bool func(int i, int j) {
    if (counter[i] != counter[j])
        return counter[i] > counter[j];
    return i < j;
}

int solution(int k, vector<int> tangerine) {
    int answer = 1;
    counter[10000000] = {0,};
    
    for (const auto& t : tangerine)
        counter[t]++;

    sort(tangerine.begin(), tangerine.end(), func);
    
    for (int i = 1; i < k; i++)
        if (tangerine[i] != tangerine[i - 1]) answer++;
    
    return answer;
}