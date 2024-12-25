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
	int totalSum = 0;
	int answer = -1;

	for (int i = 0; i < 10; i++)
		cin >> mushrooms[i];
	
	for (int i = 0; i < 10; i++)
	{
		totalSum += mushrooms[i];

		if (totalSum >= 100)
		{
			int diff1 = abs(totalSum - 100);
			int diff2 = abs(totalSum - mushrooms[i] - 100);

			if (diff1 <= diff2)
				answer = totalSum;

			else if (diff1 > diff2)
				answer = totalSum - mushrooms[i];

			cout << answer;
			return 0;
		}
	}

	answer = totalSum;
	cout << answer;

	return 0;
}