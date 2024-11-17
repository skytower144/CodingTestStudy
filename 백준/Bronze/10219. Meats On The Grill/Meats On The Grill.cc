#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--)
	{
		int h, w;
		cin >> h >> w;

		vector<vector<char>> grill(h, vector<char>(w, 0));

		for (int i = 0; i < h; i++)
		{
			string line;
			cin >> line;
			
			for (int j = 0; j < w; j++)
				grill[i][j] = line[w - j - 1];
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				cout << grill[i][j];
			cout << '\n';
		}
	}
	return 0;
}