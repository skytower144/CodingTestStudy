#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int antennas, eyes;
    cin >> antennas >> eyes;

    if (antennas >= 3 && eyes <= 4)
        cout << "TroyMartian" << '\n';
    
    if (antennas <= 6 && eyes >= 2)
        cout << "VladSaturnian" << '\n';
    
    if (antennas <= 2 && eyes <= 3)
        cout << "GraemeMercurian" << '\n';
    
    return 0;
}