#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> common;

bool compare(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.first < p2.first)
		return false;

	if (p1.first > p2.first)
		return true;

	return p1.second < p2.second;
}

void CreateCommon(vector<pair<int, int>>& a, vector<pair<int, int>>& b)
{
	sort(a.begin(), a.end(), compare);
	sort(b.begin(), b.end(), compare);

	int aIdx = 0;
	int bIdx = 0;

	int lastAidx = -1;
	int lastBidx = -1;

	while (aIdx < a.size() && bIdx < b.size())
	{
		if (a[aIdx].first > b[bIdx].first)
			aIdx++;

		else if (a[aIdx].first < b[bIdx].first)
			bIdx++;

		else
		{
			if (common.empty())
			{
				common.push_back(a[aIdx].first);
				lastAidx = a[aIdx].second;
				lastBidx = b[bIdx].second;
			}

			else
			{
				if (lastAidx < a[aIdx].second && lastBidx < b[bIdx].second)
				{
					common.push_back(a[aIdx].first);
					lastAidx = a[aIdx].second;
					lastBidx = b[bIdx].second;
					aIdx++;
					bIdx++;
				}
				else if (lastAidx >= a[aIdx].second)
					aIdx++;

				else if (lastBidx >= b[bIdx].second)
					bIdx++;
			}
		}
	}
}

int main()
{
	int n, m, num;
	vector<pair<int, int>> aSeq;
	vector<pair<int, int>> bSeq;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		aSeq.push_back({ num, i });
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		bSeq.push_back({ num, i });
	}
	CreateCommon(aSeq, bSeq);

	cout << common.size() << '\n';
	for (int i = 0; i < common.size(); i++)
		cout << common[i] << " ";

	return 0;
}