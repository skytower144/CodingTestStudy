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

	string a, b;
	cin >> a >> b;

	int alpha1[26] = {};
	int alpha2[26] = {};

	for (char& c : a)
		alpha1[c - 'a']++;

	for (char& c : b)
		alpha2[c - 'a']++;

	int answer = 0;

	for (int i = 0; i < 26; i++)
		answer += abs(alpha1[i] - alpha2[i]);
	cout << answer;
	return 0;
}