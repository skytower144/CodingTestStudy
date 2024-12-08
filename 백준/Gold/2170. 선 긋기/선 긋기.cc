#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int answer = 0;
	int start = 0;
	int end = 0;

	vector<pair<int, int>> points;

	while (n--)
	{
		cin >> start >> end;
		points.push_back({ start, end });
	}

	sort(points.begin(), points.end());

	int lastIdx = points[0].second;

	answer += points[0].second - points[0].first;

	for (int i = 1; i < points.size(); i++)
	{
		if (lastIdx <= points[i].first)
			answer += points[i].second - points[i].first;

		else
			answer += max(0, points[i].second - lastIdx);

		lastIdx = max(lastIdx, points[i].second);
	}

	cout << answer;

	return 0;
}