#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	/*
		키 순으로 들어오기 때문에 현재 사람이 들어갈 때 
		앞서 들어간 사람들보다 항상 크기 때문에 키를 비교할 필요가 없음

		따라서 빈 칸에만 집중
		자신이 건너뛸 칸은 자신보다 키 큰 사람을 위해 남겨둠
	*/
	vector<int> people(n, 0);
	int tallerCount;

	for (int i = 0; i < n; i++)
	{
		cin >> tallerCount;

		for (int j = 0; j < n; j++)
		{
			if (people[j])
				continue;

			tallerCount--;

			if (tallerCount < 0)
			{
				people[j] = i + 1;
				break;
			}
		}
	}
	for (int i = 0; i < people.size(); i++)
		cout << people[i] << " ";

	return 0;
}