#include <iostream>
#include <string>

using namespace std;

int main()
{
	string names[3];
	int answer = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> names[i];
		if (isdigit(names[i][0]))
		{
			answer = stoi(names[i]);
			answer += 3 - i;
			break;
		}
	}
	if (answer % 3 == 0)
	{
		if (answer % 5 == 0)
			cout << "FizzBuzz";
		else
			cout << "Fizz";
	}
	else
	{
		if (answer % 5 == 0)
			cout << "Buzz";
		else
			cout << answer;
	}
	return 0;
}