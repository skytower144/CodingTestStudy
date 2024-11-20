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

	vector<int> numbers(10, 0);
	bool flip = false;

	while (n > 0)
	{
		int num = n % 10;

		if (num == 6 || num == 9)
		{
			flip = !flip;
			num = flip ? 6 : 9;
		}
		numbers[num]++;
		n /= 10;
	}
	int max = *max_element(numbers.begin(), numbers.end());
	cout << max;

	return 0;
}