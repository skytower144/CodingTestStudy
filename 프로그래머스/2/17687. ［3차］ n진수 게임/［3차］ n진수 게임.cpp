#include <string>
#include <vector>
#include <iostream>

using namespace std;

string ConvertNumToString(int num, int n)
{
    if (num == 0) return "0";
    string temp = "";
    string convertedLeft;
    
    while (num)
    {
        int left = num % n;
        
        if (left >= 10 && left <= 15) 
            convertedLeft = 'A' + (left - 10);
        else
            convertedLeft = to_string(left);
        
        temp = convertedLeft + temp;
        num /= n;
    }
    return temp;
}
void CreateSequence(vector<char>& sequence, int base, int people, int rounds)
{
    for (int i = 0; i < people * rounds; i++)
    {
        string convertedString = ConvertNumToString(i, base);
        
        for (auto c : convertedString)
            sequence.push_back(c);
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<char> sequence;
    
    CreateSequence(sequence, n, m, t);
    
    for (int i = 0; i < t; i++)
        answer += sequence[m * i + p - 1];
    
    return answer;
}