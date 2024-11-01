#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int answer1 = a + b - c;
	string first = to_string(a) + to_string(b);
	int answer2 = stoi(first) - c;

	cout << answer1 << '\n' << answer2;
	return 0;
}

