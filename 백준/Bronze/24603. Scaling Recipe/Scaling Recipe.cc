#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x, y;
	cin >> n >> x >> y;

	for (int i = 0; i < n; i++)
	{
		int ingredient;
		cin >> ingredient;

		cout << ingredient * y / x << '\n';
	}
	return 0;
}