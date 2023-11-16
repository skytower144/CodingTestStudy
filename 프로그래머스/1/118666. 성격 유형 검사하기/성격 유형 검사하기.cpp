#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    vector<vector<char>> benchmark = {
        {'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}
    };
    map<char, int> stylePoint = {
        {'R', 0}, {'T', 0}, {'C', 0}, {'F', 0},
        {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0},
    };
    int points[8] = {0, 3, 2, 1, 0, 1, 2, 3};
    int choice = 0;
    char type1, type2;
    string answer = "";
    
    for (int i = 0; i < choices.size(); i++) {
        choice = choices[i];
        type1 = survey[i][0], type2 = survey[i][1];
        choice < 4 ? stylePoint[type1] += points[choice] : stylePoint[type2] += points[choice];
    }
    for (auto b : benchmark)
        answer += stylePoint[b[0]] >= stylePoint[b[1]] ? b[0] : b[1];
    
    return answer;
}