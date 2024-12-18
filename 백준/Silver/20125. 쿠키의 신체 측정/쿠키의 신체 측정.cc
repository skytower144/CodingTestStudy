#include <iostream>
using namespace std;

int CalcCookieBodySize(char** arr, int hearPosi[2], int increX, int increY, int size);
int CalcCookieLegSize(char** arr, int heartPosi[2], int increX, int increY, int size);

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int size = 0, count = 0;
    int heartPosi[2] = { -1 };
    int result[5]{ 0 }, index = 0;
    cin >> size;
    char** arr = new char* [size] {0};
    for (int i = 0; i < size; i++)
    {
        arr[i] = new char[size + 1] {0};
        cin >> arr[i];
    }
    for (int i = 1; i < size - 1; i++)
    {
        for (int j = 1; j < size - 1; j++)
        {
            if (arr[i - 1][j] != '*') continue;
            if (arr[i + 1][j] != '*') continue;
            if (arr[i][j - 1] != '*') continue;
            if (arr[i][j + 1] != '*') continue;
            heartPosi[0] = i;
            heartPosi[1] = j;
            break;
        }
        if (heartPosi[0] != -1)break;
    }
    result[0] = CalcCookieBodySize(arr, heartPosi, 0, -1, size);
    result[1] = CalcCookieBodySize(arr, heartPosi, 0, 1, size);
    result[2] = CalcCookieBodySize(arr, heartPosi, 1, 0, size);
    result[3] = CalcCookieLegSize(arr, heartPosi, -1, 1, size);
    result[4] = CalcCookieLegSize(arr, heartPosi, 1, 1, size);
    for (int i = 0; i < 2; i++)
        cout << heartPosi[i] + 1 << " ";
    cout << "\n";
    for (int i = 0; i < 5; i++)
        cout << result[i] << " ";

    delete[] arr;
    arr = nullptr;
    return 0;
}

int CalcCookieBodySize(char** arr, int heartPosi[2], int increX, int increY, int size)
{
    int x = heartPosi[0], y = heartPosi[1];
    int result = 0;
    while (true)
    {
        x += increX;
        y += increY;
        if (x < 0 || x >= size) break;
        if (y < 0 || y >= size) break;
        if (arr[x][y] != '*')break;
        result++;
    }
    return result;
}
int CalcCookieLegSize(char** arr, int heartPosi[2], int increX, int increY, int size)
{
    int x = heartPosi[1] + increX, y = heartPosi[0] + increY;
    int result = 1;
    if (x < 0 || x >= size) return 0;
    if (y < 0 || y >= size) return 0;
    while (arr[y][x] != '*')
    {
        y += 1;
    }
    while (true)
    {
        y += 1;
        if (y < 0 || y >= size) break;
        if (arr[y][x] != '*')break;
        result++;
    }
    return result;
}