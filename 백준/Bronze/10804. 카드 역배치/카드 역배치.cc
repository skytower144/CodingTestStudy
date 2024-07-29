#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums;
	for (int i = 1; i <= 20; i++)
		nums.push_back(i);

	int repeat = 10;
	int a, b;
	while (repeat--)
	{
		cin >> a >> b;
		a -= 1;
		b -= 1;

		for (int i = 0; i < (b - a + 1) / 2; i++)
		{
			int temp = nums[a + i];
			nums[a + i] = nums[b - i];
			nums[b - i] = temp;
		}
	}
	for (const auto& num : nums)
		cout << num << " ";

    return 0;
}