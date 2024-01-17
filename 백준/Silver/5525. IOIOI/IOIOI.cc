#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    string s;
    cin >> n >> m >> s;

    string p = "IOI";
    for (int i = 2; i <= n; i++)
        p += "OI";
    
    int answer = 0;
    int idx = 0;
    while (idx < m) {
        idx = s.find(p, idx);

        if (idx == string::npos)
            break;
        
        // cout << "found at : " << idx << '\n';
        idx++;
        answer++;
    }
    cout << answer;   
    return 0;
}