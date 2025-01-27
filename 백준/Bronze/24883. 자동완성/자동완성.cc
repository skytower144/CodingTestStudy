#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	char c;
	cin >> c;

	if (c == 'n' || c == 'N')
		cout << "Naver D2";
	else
		cout << "Naver Whale";

	return 0;
}