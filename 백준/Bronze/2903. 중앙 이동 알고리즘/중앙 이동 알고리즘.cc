#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>;

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    int verticesPerEdge = pow(2, n) + 1;
    int answer = verticesPerEdge * verticesPerEdge;

    cout << answer;

    return 0;
}
