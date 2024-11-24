#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x, y;
	cin >> n >> x >> y;

	double multiply = (double)y / x;
	vector<int> ingredients(n, 0);

	for (int i = 0; i < n; i++)
		cin >> ingredients[i];

	for (int i = 0; i < n; i++)
		cout << (int)round(ingredients[i] * multiply) << '\n';

	return 0;
}