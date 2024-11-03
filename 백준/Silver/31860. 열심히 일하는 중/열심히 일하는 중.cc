#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	priority_queue<int> q;
	vector<int> schedule;
	int importance;

	for (int i = 0; i < n; i++)
	{
		cin >> importance;
		q.push(importance);
	}
	while (!q.empty())
	{
		int task = q.top();
		q.pop();

		int previousComfort = schedule.empty() ? 0 : schedule.back();
		int comfort = previousComfort / 2 + task;
		schedule.push_back(comfort);
		
		task -= m;
		if (task > k)
			q.push(task);
	}
	int size = schedule.size();
	cout << size << '\n';

	for (int i = 0; i < size; i++)
		cout << schedule[i] << '\n';
}