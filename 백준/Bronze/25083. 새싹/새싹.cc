#include <iostream>
#include <vector>

using namespace std;


int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<vector<string>> sprout = {
        {"         ,r'\"7"},
        {"r`-_   ,'  ,/"},
        {" \\. \". L_r'"},
        {"   `~\\/"},
        {"      |"},
        {"      |"}
    };

    for (auto line : sprout) {
        for (auto c : line)
            cout << c << '\n';
    }    
    return 0;
}