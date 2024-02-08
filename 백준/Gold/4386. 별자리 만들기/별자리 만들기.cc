#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector<double> parents;

double FindParent(double x) {
    if (parents[x] != x)
        parents[x] = FindParent(parents[x]);
    return parents[x];
}
void UnionParent(double a, double b) {
    int parentA = FindParent(a);
    int parentB = FindParent(b);

    if (parentA < parentB)
        parents[parentB] = parentA;
    else
        parents[parentA] = parentB;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<vector<double>> stars;
    vector<vector<double>> edges;
    double x, y, distance;

    for (double i = 0; i < n; i++)
        parents.push_back(i);

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        stars.push_back({x, y});
    }
    for (double i = 0; i < n - 1; i++) {
        for (double j = i + 1; j < n; j++) {
            distance = sqrt(pow(stars[i][0] - stars[j][0], 2) + pow(stars[i][1] - stars[j][1], 2));
            edges.push_back({distance, i, j});
        }
    }
    sort(edges.begin(), edges.end());
    double answer = 0;

    for (const auto& e : edges) {
        if (FindParent(e[1]) != FindParent(e[2])) {
            UnionParent(e[1], e[2]);
            answer += e[0];
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << answer;
    return 0;
}