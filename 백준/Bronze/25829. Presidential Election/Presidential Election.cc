#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int electoral1 = 0, electoral2 = 0;
	int total1 = 0, total2 = 0;
	int electoral, first, second;

	for (int i = 0; i < n; i++)
	{
		cin >> electoral >> first >> second;

		if (first < second)
		{
			electoral2 += electoral;
		}
		else if (first > second)
		{
			electoral1 += electoral;
		}
		total1 += first;
		total2 += second;
	}
	if (total1 > total2 && electoral1 > electoral2)
		cout << 1;

	else if (total1 < total2 && electoral1 < electoral2)
		cout << 2;

	else
		cout << 0;

	return 0;
}