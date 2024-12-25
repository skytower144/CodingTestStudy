#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> mushrooms(10);
	int answer = 0;

	for (int i = 0; i < 10; i++)
		cin >> mushrooms[i];
	
	for (int i = 0; i < 10; i++)
	{
		if (abs(answer - 100) < abs(answer + mushrooms[i] - 100))
			break;

		answer += mushrooms[i];
	}

	cout << answer;
	return 0;
}