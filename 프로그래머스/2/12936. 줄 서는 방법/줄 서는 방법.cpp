#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
long long K;
long long permu[21] = {1, 1, 0,};
vector<int> taken;

long long Permu(long long n) {
    if (permu[n]) return permu[n];
    return permu[n] = n * Permu(n - 1);
}
void Comb(vector<int>& answer, long long count, int current) {
    for (int i = 1; i <= N; i++) {
        if (taken[i]) continue;
        count += Permu(current);
        
        if (count >= K) {
            answer.push_back(i);
            taken[i] = 1;
            
            if (count == K) {
                for (int j = N; j >= 1; j--) {
                    if (taken[j]) continue;
                    answer.push_back(j);
                }
                return;
            }
            else
                count -= Permu(current);
                
            Comb(answer, count, current - 1);
            return;
        }
    }
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    N = n, K = k;
    taken = vector<int>(21, 0);
    
    Comb(answer, 0, N - 1);
    return answer;
}