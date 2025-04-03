#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

struct Grade
{
    string name;
    int kor;
    int eng;
    int math;
};

bool compare(Grade& a, Grade& b)
{
    if (a.kor != b.kor)
        return a.kor > b.kor;

    if (a.eng != b.eng)
        return a.eng < b.eng;

    if (a.math != b.math)
        return a.math > b.math;

    return a.name < b.name;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    vector<Grade> grades = vector<Grade>(n);

    for (int i = 0; i < n; i++)
        cin >> grades[i].name >> grades[i].kor >> grades[i].eng >> grades[i].math;

    sort(grades.begin(), grades.end(), compare);

    for (auto grade : grades)
        cout << grade.name << '\n';

    return 0;
}