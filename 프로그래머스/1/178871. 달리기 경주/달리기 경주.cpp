#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    unordered_map<string, int> ranks;
    int back, front;
    string frontName;
    
    for (int i = 0; i < players.size(); i++)
        ranks[players[i]] = i;
    
    for (const auto call : callings) {
        back = ranks[call];
        front = back - 1;
        frontName = answer[front];
        
        ranks[call] = front;
        ranks[frontName] = back;
        
        answer[front] = call;
        answer[back] = frontName;
    }
    return answer;
}