#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer, N;
vector<pair<int, int>> cords;

bool CanPlace(int x, int y) {
    for (const auto& [cordX, cordY] : cords) {
        if (x == cordX || abs(x - cordX) == abs(y - cordY))
            return false;
    }
    return true;
}
void PlaceQueen(int y) {
    if (y == N) {
        answer++;
        return;
    }
    for (int x = 0; x < N; x++) {
        if (CanPlace(x, y)) {
            cords.push_back({x, y});
            PlaceQueen(y + 1);
            cords.pop_back();
        }
    }
}
int solution(int n) {
    cords = vector<pair<int, int>>();
    answer = 0;
    N = n;
    
    PlaceQueen(0);
    return answer;
}