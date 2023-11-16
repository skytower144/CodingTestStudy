#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int width = -1, height = -1, temp = 0;
    for (auto& size : sizes) {
        if (size[0] < size[1]) {
            temp = size[0];
            size[0] = size[1];
            size[1] = temp;
        }
        if (width < size[0]) width = size[0];
        if (height < size[1]) height = size[1];
    }
    return width * height;
}