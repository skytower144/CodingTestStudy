#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int myNums[46] = {0};
    int minWin = 0, maxWin = 0;
    
    for (auto num : lottos)
        num ? myNums[num]++ : maxWin++;
    
    for (auto num : win_nums)
        if (myNums[num]) minWin++;
    
    maxWin += minWin;
    return {min(6 - maxWin + 1, 6), min(6 - minWin + 1, 6)};
}