#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool flag = false;

void GetSolution(vector<int>& left, vector<int>& temp, vector<bool>& visited)
{
	if (flag)
		return;

	if (temp.size() == left.size())
	{
		for (int i = 0; i < temp.size(); i++)
		{
			int count = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				count += temp[i] < temp[j];
				if (count > left[temp[i] - 1])
					return;
			}
			if (count != left[temp[i] - 1])
				return;
		}

		for (int& num : temp)
			cout << num << " ";
		cout << endl;
		flag = true;
		return;
	}

	for (int i = 0; i < left.size(); i++)
	{
		if (flag)
			return;

		if (visited[i])
			continue;

		temp.push_back(i + 1);
		visited[i] = true;

		GetSolution(left, temp, visited);

		visited[i] = false;
		temp.pop_back();
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> left(n);

	for (int i = 0; i < n; i++)
		cin >> left[i];

	vector<int> temp;
	vector<bool> visited(left.size(), false);

	GetSolution(left, temp, visited);
	return 0;
}