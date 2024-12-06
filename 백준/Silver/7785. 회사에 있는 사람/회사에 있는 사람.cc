#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

bool compare(string& a, string& b)
{
	return a > b;
}

int main()
{

	unordered_map<string, bool> record;

	int n;
	cin >> n;
	getchar();

	string info;
	string name;
	string action;

	for (int i = 0; i < n; i++)
	{
		getline(cin, info);
		stringstream ss(info);

		ss >> name >> action;

		if (action == "enter")
			record[name] = true;

		else if (action == "leave")
			record.erase(name);
	}

	vector<string> names;

	for (const auto& kv : record)
		names.push_back(kv.first);

	sort(names.begin(), names.end(), compare);
	
	for (const auto& name : names)
		cout << name << '\n';

	return 0;
}