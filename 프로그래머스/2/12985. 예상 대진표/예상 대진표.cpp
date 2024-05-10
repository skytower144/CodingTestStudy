#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int group = 2;
    vector<int> players;
    
    for (int i = 1; i <= n; i++)
        players.push_back(i);
    
    while (players[a - 1] != players[b - 1]) {
        for (int i = 0; i < n; i++)
            players[i] = i / group + 1;
        group *= 2;
        answer++;
    }
    return answer;
}