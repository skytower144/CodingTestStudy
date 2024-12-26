#include <string>
#include <vector>

using namespace std;

int answer = 0;

void Comb(int index, int count, int sum, vector<int>& number)
{
    if (count == 3)
    {
        answer += (sum == 0);
        return;
    }
    
    for (int i = index; i < number.size(); i++)
        Comb(i + 1, count + 1, sum + number[i], number);
}

int solution(vector<int> number) {
    Comb(0, 0, 0, number);
    return answer;
}