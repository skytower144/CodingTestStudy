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

	int alpha[26] = {};

	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;

		alpha[name[0] - 'a']++;
	}

	bool nobody = true;

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] >= 5)
		{
			nobody = false;
			cout << char('a' + i);
		}
	}
	if (nobody)
		cout << "PREDAJA";

	return 0;
}