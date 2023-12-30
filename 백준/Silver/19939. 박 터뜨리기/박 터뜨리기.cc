#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int answer = 0;
    int totalBalls = k * (k + 1) / 2;
    if (totalBalls > n) 
        answer = -1;
    
    else {
        n -= totalBalls;
        if (n % k)
            answer = k;
        else
            answer = k - 1;
    }
    cout << answer;
    return 0;   
}
/*
12 4
======

1 2 3 4 = 10

=> 2개 남음

마지막 자리부터 1개씩 채워나감
1. 마지막까지 못 채울 경우: n % 남은 공 > 0
1.....(4+1) => (4+1) - 1 = 4
               (k + 1) - 1 = k

2. 마지막까지 딱 맞춰서 채울 경우: n % 남은 공 == 0
(1+1)...(4+1) => (4+1) - (1+1) = 5
                 (k + 1) - (1+1) = k - 1

*/