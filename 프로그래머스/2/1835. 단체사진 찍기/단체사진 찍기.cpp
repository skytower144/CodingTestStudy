#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

typedef struct CharCondition {
    char target;
    char condition;
    int distance;
} CharCondition;

unordered_map<char, vector<CharCondition>> charMap;
vector<int> charPos;
vector<char> people;
int answer;

bool CanBeNext(char person1, int pos) {
    if (charPos[person1 - 'A'] != -1)
        return false;
    
    if (!charMap.count(person1))
        return true;
    
    for (const auto& c : charMap[person1]) {
        char person2 = c.target;
        bool flag;
    
        if (charPos[person2 - 'A'] == -1)
            continue;

        int distance = abs(charPos[person2 - 'A'] - pos);

        switch (c.condition) {
            case '=':
                flag = distance == c.distance;
                break;
            case '<':
                flag = distance < c.distance;
                break;
            case '>':
                flag = distance > c.distance;
                break;
        }
        if (!flag) return false;
    }
    return true;
}
void ArrangePeople(int pos) {
    if (pos == 8) {
        answer++;
        return;
    }
    for (const auto& person : people) {
        if (CanBeNext(person, pos)) {
            charPos[person - 'A'] = pos;
            ArrangePeople(pos + 1);
            charPos[person - 'A'] = -1;
        }
    }
}
int solution(int n, vector<string> data) {
    answer = 0;
    charMap = unordered_map<char, vector<CharCondition>>();
    charPos = vector<int>(26, -1);
    people = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    for (int i = 0; i < n; i++) {
        charMap[data[i][0]].push_back({data[i][2], data[i][3], data[i][4] - '0' + 1});
        charMap[data[i][2]].push_back({data[i][0], data[i][3], data[i][4] - '0' + 1});
    }
    ArrangePeople(0);
    return answer;
}