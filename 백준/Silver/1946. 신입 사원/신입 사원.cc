#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int excluded = 0;

		int n;
		cin >> n;

		vector<pair<int, int>> people;

		for (int i = 0; i < n; i++)
		{
			int resume, interview;
			cin >> resume >> interview;

			people.push_back({ resume, interview });
		}

		sort(people.begin(), people.end(), compare);
		int ct = people.size();

		vector<pair<int, int>> stack;
		stack.push_back(people[0]);

		for (int i = 1; i < ct; i++)
		{
			if (stack.back().first < people[i].first && stack.back().second < people[i].second)
				continue;

			while (stack.back().first > people[i].first && stack.back().second > people[i].second)
				stack.pop_back();

			stack.push_back(people[i]);
		}

		cout << stack.size() << '\n';
	}
	
	return 0;
}