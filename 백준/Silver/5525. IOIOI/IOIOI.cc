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

    string temp = "";
    int answer = 0;
    int count = 0;
    bool last = false;

    for (int i = 0; i < m; i++) {
        if (temp == "" && s[i] == 'I') {
            temp += s[i];
            count = 0;
        }
        else if (temp.back() == 'O' && s[i] == 'I') {
            temp += s[i];
            count++;
        }
        else if (temp.back() == 'I' && s[i] == 'O')
            temp += s[i];
        
        else {
            if (count >= n) {
                answer += count - n + 1;
                if (i == m - 1)
                    last = true;
            }
            if (s[i] == 'I')
                temp = 'I';
            else
                temp = "";
            count = 0;
        }
    }
    if (!last && count >= n)
        answer += count - n + 1;
    cout << answer;
    return 0;
}