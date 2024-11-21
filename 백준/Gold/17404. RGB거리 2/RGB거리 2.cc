#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int>> nums(n, vector<int>(3, 0));

	for (int i = 0; i < n; i++)
		cin >> nums[i][0] >> nums[i][1] >> nums[i][2];

	int answer = INT_MAX;

	for (int i = 0; i < 3; i++)
	{
		vector<vector<int>> dp(n, vector<int>(3, 0));
		dp[0][0] = dp[0][1] = dp[0][2] = INT_MAX;
		dp[0][i] = nums[0][i];

		for (int j = 1; j < n; j++)
		{
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]);

			for (int k = 0; k < 3; k++)
			{
				if (dp[j][k] != INT_MAX)
					dp[j][k] += nums[j][k];
			}

			if (j == n - 1)
				dp[j][i] = INT_MAX;
		}
		int result = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
		answer = min(answer, result);
	}
	cout << answer;

	return 0;
}