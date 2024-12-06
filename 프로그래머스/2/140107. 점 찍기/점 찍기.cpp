#include <string>
#include <vector>
#include <iostream>
#include <cmath>

typedef long long ll;

using namespace std;

/*
x^2 + y^2 = d^2


*/

long long solution(int k, int d) {
    ll answer = 0;
    ll limit = (ll)d * d;
    
    for (int i = 0; i * k <= d; i++)
    {
        ll amount = (ll)sqrt(limit - pow(i * k, 2)) / k + 1;
        answer += amount;
    }
    
    return answer;
}