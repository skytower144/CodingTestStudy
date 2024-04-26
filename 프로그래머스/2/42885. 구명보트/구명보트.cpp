#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int sum = 0;
    
    sort(people.begin(), people.end());

    for (int l = 0, r = people.size() - 1; l <= r; r--) {
        sum = people[l] + people[r];
        answer++;
        
        if (sum <= limit)
            l++;
    }
    return answer;
}