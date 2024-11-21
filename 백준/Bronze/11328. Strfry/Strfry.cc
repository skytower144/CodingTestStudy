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

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		if (a == b)
			cout << "Possible" << '\n';
		else
			cout << "Impossible" << '\n';
	}

	return 0;
}