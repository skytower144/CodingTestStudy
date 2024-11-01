#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, t, p;
	vector<int> shirts(6, 0);

	cin >> n;
	for (int i = 0; i < shirts.size(); i++)
		cin >> shirts[i];

	cin >> t >> p;

	int shirtBundle = 0;
	int penBundle = 0;
	int penCount = 0;

	for (int i = 0; i < shirts.size(); i++)
	{
		shirtBundle += shirts[i] / t;
		if (shirts[i] % t)
			++shirtBundle;
	}
	penBundle = n / p;
	penCount = n % p;

	cout << shirtBundle << '\n' << penBundle << " " << penCount;
	return 0;
}