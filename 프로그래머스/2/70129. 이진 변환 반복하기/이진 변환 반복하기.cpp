#include <string>
#include <vector>
#include <iostream>

using namespace std;

string ConvertBinary(int num)
{
    string converted  = "";
    while (num)
    {
        converted = to_string(num % 2) + converted;
        num /= 2;
    }
    return converted;
}

vector<int> solution(string s) {
    vector<int> answer;
    int convertCount = 0;
    int erasedCount = 0;
    
    while (s != "1")
    {
        bool wasConverted = false;
        int length = 0;
        convertCount++;
        
        for (const auto& c : s)
        {
            if (c != '0')
                length++;
        }
        erasedCount += s.size() - length;
        s = ConvertBinary(length);
    }
    answer = {convertCount, erasedCount};
    return answer;
}