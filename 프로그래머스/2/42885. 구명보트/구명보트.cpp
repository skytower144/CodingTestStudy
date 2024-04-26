#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, sum = 0;
    int left = 0;
    int right = people.size() - 1;
    
    sort(people.begin(), people.end());

    while (left < right) {
        sum = !sum ? people[left] + people[right] : sum + people[right];
        
        if (sum > limit) {
            sum -= people[right];
            right--;
        }
        else if (sum <= limit) {
            left++;
            right--;
            sum = (left == right) ? people[left] : 0;
        }
        answer++;
    }
    if (sum) answer++;
    return answer;
}