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

	int n;
	cin >> n;

	vector<int> students(n, 0);

	for (int i = 1; i <= n; i++)
	{
		int count;
		cin >> count;

		for (int j = 0; j < count; j++)
			students[i - 1 - j] = students[i - 2 - j];

		students[i - 1 - count] = i;
	}

	for (auto s : students)
		cout << s << " ";
	cout << endl;

	return 0;
}