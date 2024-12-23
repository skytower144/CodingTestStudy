#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    /*
        cf) https://yejin72.tistory.com/109
        
        1:1,    2:3,       1:2,        3:4
                3:2,       2:1,        4:3
             
        w:w,    w:3/2w,    w:2w,       w:4/3w,
                w:2/3w,    w:1/2w,     w:3/4w
    */
    
    long long answer = 0;
    unordered_map<double, int> weightMap;
    
    for (int i = 0; i < weights.size(); i++)
    {
        int w = weights[i];
        
        answer += weightMap[w];
        answer += weightMap[w * 3 / 2.0];
        answer += weightMap[w * 2 / 3.0];
        answer += weightMap[w * 2.0];
        answer += weightMap[w / 2.0];
        answer += weightMap[w * 4 / 3.0];
        answer += weightMap[w * 3 / 4.0];
        
        weightMap[w]++;
    }
    
    return answer;
}