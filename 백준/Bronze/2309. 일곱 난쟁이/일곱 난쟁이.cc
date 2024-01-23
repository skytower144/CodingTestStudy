#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> dwarves(9, 0);
bool finished = false;

void FindDwarf(vector<int> temp, int index, int sum) {
    if (finished) return;

    if (temp.size() == 7) {
        if (sum == 100) {
            finished = true;
            sort(temp.begin(), temp.end());

            for (auto dwarf : temp)
                cout << dwarf << '\n';
        }
        return;
    }
    if (index > 8) return;
    temp.push_back(dwarves[index]);
    FindDwarf(temp, index + 1, sum + dwarves[index]);

    temp.pop_back();
    FindDwarf(temp, index + 1, sum);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i = 0; i < 9; i++)
        cin >> dwarves[i];

    vector<int> temp;
    FindDwarf(temp, 0, 0);

    return 0;
}