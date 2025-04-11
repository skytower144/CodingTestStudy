#include <string>
#include <vector>
#include <climits>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
    
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;
    
    for (auto r : results)
        graph[r[0]][r[1]] = 1;

    // Floyd-Warshall
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;

                if (graph[i][k] == INT_MAX)
                    continue;
                
                if (graph[k][j] == INT_MAX)
                    continue;
                
                // i -> j vs i -> k -> j
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        unordered_set<int> nums;
        
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            
            if (graph[i][j] != INT_MAX || graph[j][i] != INT_MAX)
                nums.insert(j);
        }

        if (nums.size() == n - 1)
            answer++;
    }
    
    return answer;
}