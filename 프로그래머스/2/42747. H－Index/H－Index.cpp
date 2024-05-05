#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater());
    
    for (int i = 1; i <= citations.size(); i++) {
        if (i > citations[i - 1])
            return i - 1;
    }
    return citations.size();
}