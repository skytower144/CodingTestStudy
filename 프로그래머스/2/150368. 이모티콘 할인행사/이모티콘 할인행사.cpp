#include <string>
#include <vector>

using namespace std;

int discount[4] = {10, 20, 30, 40};
vector<int> answer;

void Calculate(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& temp)
{
    int subscribers = 0;
    int sales = 0;
    
    for (int i = 0; i < users.size(); i++)
    {
        int totalPrice = 0;
        
        for (int j = 0; j < emoticons.size(); j++)
        {
            if (users[i][0] > temp[j])
                continue;
            
            totalPrice += emoticons[j] * (1 - temp[j] * 0.01);
        }
        
        if (totalPrice >= users[i][1])
            subscribers++;
        else
            sales += totalPrice;
    }
    
    if (answer.empty())
    {
        answer.push_back(subscribers);
        answer.push_back(sales);
    }
    else
    {
        if ((answer[0] < subscribers) || (answer[0] == subscribers && answer[1] < sales))
        {
            answer[0] = subscribers;
            answer[1] = sales;
        }
    }
}

void Comb(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& temp)
{
    if (temp.size() == emoticons.size())
    {
        Calculate(users, emoticons, temp);
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        temp.push_back(discount[i]);
        Comb(users, emoticons, temp);
        temp.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> temp;
    Comb(users, emoticons, temp);
    
    return answer;
}