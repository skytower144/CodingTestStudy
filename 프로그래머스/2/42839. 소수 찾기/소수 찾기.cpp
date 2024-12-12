#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

const int MAX = 10000000;

vector<bool> isPrime(10000000, true);
unordered_map<int, bool> numMap;

void InitPrime()
{
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    
    for (int i = 2; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;
        
        for (int j = 2; i * j <= MAX; j++)
            isPrime[i * j] = false;
    }
}

void Comb(string& num, string& temp, vector<bool>& visited)
{
    if (!temp.empty())
    {
        int converted = stoi(temp);
        
        if (isPrime[converted])
            numMap[stoi(temp)] = true;
        
        if (temp.size() >= num.size())
            return;
    }
    
    for (int i = 0; i < num.size(); i++)
    {
        if (visited[i])
            continue;
        
        temp.push_back(num[i]);
        visited[i] = true;
        
        Comb(num, temp, visited);
        
        temp.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    string temp = "";
    
    vector<bool> visited(numbers.size(), false);
    
    InitPrime();
    Comb(numbers, temp, visited);
    
    answer = numMap.size();
    return answer;
}