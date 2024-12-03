#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	string line;
	cin >> line;

	int count = 0;
	vector<char> stack;

	for (int i = 0; i < line.size(); i++)
	{
		if (i > 0 && stack.back() == '(' && line[i] == ')')
		{
			stack.pop_back();
			stack.push_back('!');
			continue;
		}

		else if (line[i] == ')')
		{
			int index = stack.size() - 1;
			int laserCount = 0;

			while (index >= 0 && stack[index] != '(')
			{
				laserCount++;
				index--;
			}
			stack.erase(stack.begin() + index);

			count += laserCount + 1;
			continue;
		}

		stack.push_back(line[i]);

		//for (auto s : stack)
		//	cout << s << " ";
		//cout << endl;
	}
	cout << count;

	return 0;
}