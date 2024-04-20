#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int row = arr1.size();
    int mid = arr1[0].size();
    int col = arr2[0].size();
    
    for (int r = 0; r < row; r++) {
        vector<int> temp;
        
        for (int c = 0; c < col; c++) {
            int result = 0;
            for (int m = 0; m < mid; m++)
                result += arr1[r][m] * arr2[m][c];
            
            temp.push_back(result);
        }
        answer.push_back(temp);
    }
    return answer;
}