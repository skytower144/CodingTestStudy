#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <unordered_map>
#define LIMIT 10000000

using namespace std;

vector<int> prime(LIMIT, 1);
unordered_map<int, int> visited;
int answer = 0;

void InitPrime() {
    prime[0] = 0;
    prime[1] = 0;
    
    for (int i = 2; i < sqrt(LIMIT); i++) {
        for (int j = 2; i * j < LIMIT; j++)
            prime[i * j] = 0;
    }
}
void CreateComb(string& current, string& numbers) {
    char temp;

    for (int i = 0; i < numbers.size(); i++) {
        current += numbers[i];
        temp = numbers[i];
        numbers.erase(i, 1);
        
        CreateComb(current, numbers);
        
        numbers.insert(i, 1, temp);
        current.pop_back();
    }
    if (current.size()) {
        int converted = stoi(current);
        if (visited.count(converted))
            return;
        
        visited[converted]++;
        if (prime[converted])
            answer++;
    }
}

int solution(string numbers) {
    InitPrime();
    string current = "";
    CreateComb(current, numbers);
    
    return answer;
}