#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<int> isPrime(n + 1, 1);
    vector<int> primes;
    
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        primes.push_back(i);
        
        for (int j = 2; i * j <= n; j++)
            isPrime[i * j] = 0;
    }
    int left = 0;
    int right = 0;
    int limit = primes.size();

    if (limit == 0) {
        cout << 0;
        return 0;
    }
    int totalSum = primes[left];
    int answer = 0;

    while (left <= right) {
        if (totalSum == n) {
            answer++;

            right++;
            if (right == limit)
                break;
            
            totalSum += primes[right];
        }
        else if (totalSum < n) {
            right++;
            if (right == limit)
                break;
            
            totalSum += primes[right];
        }
        else {
            totalSum -= primes[left];
            left++;
        }
    }
    cout << answer;
    return 0;
}