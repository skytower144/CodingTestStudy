#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int yPlan[2] = {30, 10};
	int mPlan[2] = {60, 15};
	int mCost = 0, yCost = 0;
	int duration;

	for (int i = 0; i < n; i++)
	{
		cin >> duration;
		mCost += (duration / mPlan[0]) * mPlan[1] + mPlan[1];
		yCost += (duration / yPlan[0]) * yPlan[1] + yPlan[1];
	}
	if (mCost < yCost)
		cout << "M " << mCost;
	else if (mCost > yCost)
		cout << "Y " << yCost;
	else
		cout << "Y M " << mCost;
    return 0;
}