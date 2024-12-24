#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, char> charMap;

string Convert(int n, int b)
{
	string converted = "";

	while (n > 0)
	{
		converted += charMap[n % b];
		n /= b;

	}

	reverse(converted.begin(), converted.end());
	return converted;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, b;
	cin >> n >> b;

	for (int i = 0; i <= 9; i++)
		charMap[i] = char(i + '0');

	for (int i = 10; i <= 35; i++)
		charMap[i] = char(i - 10 + 'A');

	string answer = Convert(n, b);
	cout << answer;

	return 0;
}