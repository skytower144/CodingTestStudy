#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;

	if (a > b)
	{
		long long temp = a;
		a = b;
		b = temp;
	}
	long long count = max((long long)0, b - a - 1);
	cout << count << '\n';

	for (long long i = a + 1; i < b; i++)
		cout << i << " ";

    return 0;
}