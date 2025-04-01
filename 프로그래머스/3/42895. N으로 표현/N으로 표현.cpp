#include <string>
#include <vector>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
        
    if (N == number)
        return 1;

    vector<vector<int>> nums = vector<vector<int>>(9);
    nums[1].push_back(N);
    
    for (int i = 2; i <= 8; i++)
    {
        int temp = N;
        
        for (int j = 0; j < i - 1; j++)
            temp = temp * 10 + N;    
        
        nums[i].push_back(temp);
        
        if (temp == number)
            return i;

        for (int j = 1; j <= i - 1; j++)
        {
            for (int t = 0; t < nums[j].size(); t++)
            {
                for (int k = 0; k < nums[i - j].size(); k++)
                {
                    vector<int> tempNums;

                    tempNums.push_back(nums[j][t] + nums[i - j][k]);
                    tempNums.push_back(nums[j][t] - nums[i - j][k]);
                    tempNums.push_back(nums[j][t] * nums[i - j][k]);

                    if (nums[i - j][k] > 0)
                        tempNums.push_back(nums[j][t] / nums[i - j][k]);

                    for (auto added : tempNums)
                    {
                        if (added == number)
                            return i;

                        nums[i].push_back(added);
                    }
                }
            }
        }
    }
    
    return answer;
}