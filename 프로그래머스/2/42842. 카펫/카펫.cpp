#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int totalBlocks = brown + yellow;
    int right = totalBlocks;
    int left = 1;
    
    while (left <= right) {
        int frame = (left + right) * 2 - 4;
        
        if (frame == brown)
            return {right, left};
        
        while (left++) {
            if (totalBlocks % left == 0) {
                right = totalBlocks / left;
                break;
            }
        }
    }
}