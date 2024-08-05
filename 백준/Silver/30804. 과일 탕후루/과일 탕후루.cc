#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
int answer = 1;
vector<int> fruits;
unordered_map<int, int> fruitMap;

void Solution(int left, int right, int count)
{
    // cout << left << ',' << right << endl;
    if (right == n)
        return;
    
    if (fruitMap.size() <= 2)
    {
        answer = max(answer, count);
        ++right;
        ++fruitMap[fruits[right]];
        ++count;
    }
    else
    {
        --fruitMap[fruits[left]];
        --count;

        if (fruitMap[fruits[left]] == 0)
            fruitMap.erase(fruits[left]);
        ++left;
    }
    Solution(left, right, count);
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

    int fruit;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> fruit;
        fruits.push_back(fruit);
    }
    Solution(0, -1, 0);
    cout << answer;
    return 0;
}