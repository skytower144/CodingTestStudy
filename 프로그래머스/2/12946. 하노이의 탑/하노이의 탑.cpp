#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void Move(int n, int from, int mid, int to) {
    if (n == 1) {
        answer.push_back({from, to});
        return;
    }
    Move(n - 1, from, to, mid);
    answer.push_back({from, to});
    Move(n - 1, mid, from, to);
}

vector<vector<int>> solution(int n) {
    answer = vector<vector<int>>();
    Move(n, 1, 2, 3);
    
    return answer;
}