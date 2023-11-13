#include <string>
#include <vector>
#include <map>

using namespace std;

string answer = "";
int leftThumb = 10, rightThumb = 12;
map<int, vector<int>> phonePos;
vector<vector<int>> phone = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
};
void InitPhonePos() {
    for (int y = 0; y < phone.size(); y++) {
        for (int x = 0; x < phone[y].size(); x++)
            phonePos[phone[y][x]] = {x, y};
    }
}
void UseThumb(int num, char side) {
    side == 'L' ? leftThumb = num : rightThumb = num;
    answer += side;
}
int GetDistance(int num1, int num2) {
    int distanceX = abs(phonePos[num1][0] - phonePos[num2][0]);
    int distanceY = abs(phonePos[num1][1] - phonePos[num2][1]);
    return distanceX + distanceY;
}
string solution(vector<int> numbers, string hand) {
    InitPhonePos();
    
    for (auto num : numbers) {
        if (num == 0) num = 11;
        
        switch (num % 3) {
            case 1:
                UseThumb(num, 'L');
                break;
            case 0:
                UseThumb(num, 'R');
                break;
            case 2:
                int lDistance = GetDistance(leftThumb, num);
                int rDistance = GetDistance(rightThumb, num);
                char side = toupper(hand[0]);
                
                if (lDistance == rDistance) UseThumb(num, side); 
                else lDistance < rDistance ? UseThumb(num, 'L') : UseThumb(num, 'R');
                break;
        }
    }
    
    return answer;
}