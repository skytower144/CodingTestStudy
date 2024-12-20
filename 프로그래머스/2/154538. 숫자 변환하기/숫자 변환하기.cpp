#include <string>
#include <vector>
#include <climits>

using namespace std;


int solution(int x, int y, int n) {
    int answer;
    vector<int> dp(y + 1, INT_MAX);

    dp[x] = 0;
    
    for (int i = x; i < y; i++)
    {
        if (dp[i] == INT_MAX)
            continue;
        
        int nx[] = {i + n, i * 2, i * 3};
        
        for (int j = 0; j < 3; j++)
        {
            if (nx[j] > y)
                continue;
            
            dp[nx[j]] = min(dp[nx[j]], dp[i] + 1);
        }
    }
    
    if (dp[y] == INT_MAX)
        dp[y] = -1;
    
    return dp[y];
}