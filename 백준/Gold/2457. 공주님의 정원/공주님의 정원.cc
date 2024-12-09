#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int Date(int month, int day)
{
	return month * 100 + day;
}

int Solution()
{
	int n;
	cin >> n;

	vector<pair<int, int>> dates;
	int startMonth, startDay, endMonth, endDay;

	while (n--)
	{
		cin >> startMonth >> startDay >> endMonth >> endDay;

		if (endMonth < 3)
			continue;

		if (endMonth == 3 && endDay == 1)
			continue;

		if (startMonth == 12)
			continue;

		dates.push_back({ Date(startMonth, startDay), Date(endMonth, endDay) });
	}

	sort(dates.begin(), dates.end(), compare);

	//cout << endl;
	//for (auto d : dates)
	//	cout << d.first << " , " << d.second << endl;
	//cout << endl;

	vector<pair<int, int>> selected;
	int start = Date(3, 1);
	int end = start;

	for (int i = 0; i < dates.size(); i++)
	{
		if (dates[i].first <= Date(3, 1) && dates[i].second >= Date(12, 1))
			return 1;

		if (start >= dates[i].first && end < dates[i].second)
		{
			selected.push_back(dates[i]);
			start = dates[i].first;
			end = dates[i].second;
		}

		if (end >= dates[i].first && end < dates[i].second)
		{
			int size = selected.size();

			if (size >= 2 && selected[size - 2].second >= dates[i].first && selected[size - 1].second <= dates[i].second)
				selected.pop_back();

			if (dates[i].first <= Date(3, 1))
				selected.pop_back();

			if (end >= Date(12, 1))
			{
				if (dates[i].second <= selected.back().second)
					selected.pop_back();
				else
					continue;
			}

			selected.push_back(dates[i]);
			end = dates[i].second;
		}

		//for (auto s : selected)
		//	cout << s.first << " " << s.second << endl;
		//cout << endl;
	}

	if (!selected.empty() && selected.back().second <= Date(11, 30))
		return 0;

	return selected.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cout << Solution();

	return 0;
}