#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int sum = 0, total = 45;
    for (auto num : numbers) sum += num;
    return total - sum;
}