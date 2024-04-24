#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int h = 3;
    int w = (brown / 2) - 1;
    
    while (w * h != brown + yellow) {
        w--;
        h++;
    }
    return {w, h};
}