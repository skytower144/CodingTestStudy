#include <stdio.h>

long dp[101][10] = {
	{0,},
	{1,1,1,1,1,1,1,1,1,1},
	{0,}
};

int main()
{
	int N;
	scanf("%d", &N);
	for(int i=2; i<=N; i++)
	{
		dp[i][0] = dp[i-1][1] % 1000000000;
		for(int k=1; k<=8; k++)
		{
			dp[i][k] = (dp[i-1][k-1] + dp[i-1][k+1]) % 1000000000; 
		}
		dp[i][9] = dp[i-1][8] % 1000000000;
	}
	long sum = 0;
	for(int k=1; k<=9; k++)
	{
		sum += dp[N][k] % 1000000000;
	}
	printf("%ld\n", sum % 1000000000); 
	return 0;
}