#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> nums(2000001, 0);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums[num]++;
	}
	int x;
	cin >> x;

	int answer = 0;

	for (int i = 1; i <= x - i; i++)
	{
		if (nums[i] > 0 && nums[x - i] > 0)
		{
			if (i == x - i)
				answer += nums[i] / 2;
			else
				answer += min(nums[i], nums[x - i]);
		}
	}
	cout << answer;

	return 0;
}