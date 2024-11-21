#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;

		int alpha1[26] = {};
		int alpha2[26] = {};

		for (char& c : a)
			alpha1[c - 'a']++;

		for (char& c : b)
			alpha2[c - 'a']++;

		bool isPossible = true;

		for (int i = 0; i < 26; i++)
		{
			if (alpha1[i] != alpha2[i])
			{
				isPossible = false;
				break;
			}
		}
		if (isPossible)
			cout << "Possible" << '\n';
		else
			cout << "Impossible" << '\n';
	}

	return 0;
}