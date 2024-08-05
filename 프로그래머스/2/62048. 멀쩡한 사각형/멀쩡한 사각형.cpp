#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
    # 직선의 방정식
    y = (y2 - y1) / (x2 - x1) * (x - x1) + y1;
    
    # 참고 (첫번째 풀이):
    https://velog.io/@nnnyeong/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%ED%92%80%EC%9D%B4-%EB%B6%84%EC%84%9D-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%A9%80%EC%A9%A1%ED%95%9C-%EC%82%AC%EA%B0%81%ED%98%95
*/
double gradient;

double GetLineY(int x)
{
    return gradient * x;
}

int GCD(int width, int height)
{
    int a = width;
    int b = height;
    
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while (b != 0)
    {
        int n = a % b;
        a = b;
        b = n;
    }
    return a;
}

long long GetSlicedCount(int width, int height)
{
    long long sliced = 0;
    for (int j = 1; j <= width; j++)
    {
        int currentSliced = 0;
        
        int floorLeft = floor(GetLineY(j - 1));
        double right = GetLineY(j);
        int floorRight = floor(right);
        
        currentSliced = floorRight - floorLeft;
        
        if (right != (int)right)
            currentSliced++;
        
        sliced += currentSliced;
        // cout << currentSliced << endl;
    }
    return sliced;
}

long long solution(int w,int h) {
    long long answer = 0;
    gradient = (double)h / w;
    
    int gcd = GCD(w, h);
    int shortX = w / gcd;
    int shortY = h / gcd;
    
    long long sliced = GetSlicedCount(shortX, shortY);
    
    answer = (long long)w * h - gcd * sliced;
    return answer;
}