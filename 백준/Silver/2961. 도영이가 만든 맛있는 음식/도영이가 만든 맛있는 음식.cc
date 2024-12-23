#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int answer;
vector<int> sour, bitter;

void Comb(int idx, int sourness, int bitterness)
{
    for (int i = idx; i < sour.size(); i++)
    {
        int prevSourness = sourness;

        if (sourness == 0)
            sourness = 1;

        sourness *= sour[i];
        bitterness += bitter[i];

        Comb(i + 1, sourness, bitterness);

        sourness = prevSourness;
        bitterness -= bitter[i];
    }

    if (sourness + bitterness != 0)
        answer = min(answer, abs(bitterness - sourness));
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;

    sour = vector<int>(n, 0);
    bitter = vector<int>(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> sour[i];
        cin >> bitter[i];
    }

    answer = abs(bitter[0] - sour[0]);
    Comb(0, 0, 0);

    cout << answer;

    return 0;
}