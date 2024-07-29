#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int count = max(0, b - a - 1);
	cout << count << '\n';

	for (int i = a + 1; i < b; i++)
		cout << i << " ";

    return 0;
}