#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <string>

using namespace std;

int Calculate_D(int num) {
    return (num * 2) % 10000;
}
int Calculate_S(int num) {
    if (num == 0) return 9999;
    return num - 1;
}
int Calculate_L(int num) {
    return (num % 1000) * 10 + (num / 1000);
}
int Calculate_R(int num) {
    return (num % 10 * 1000) + (num / 10);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    char commands[] = {'D', 'S', 'L', 'R'};

    while (t--) {
        int a, b;
        cin >> a >> b;

        queue<int> q;
        vector<string> tracker(10000, "");
        vector<int> visited(10000, 0);

        visited[a] = 1;
        q.push(a);

        while(!q.empty() || !visited[b]) {
            int currentNum = q.front();
            int result;
            q.pop();

            for (int i = 0; i < 4; i++) {
                switch (i) {
                    case 0:
                        result = Calculate_D(currentNum);
                        break;
                    
                    case 1:
                        result = Calculate_S(currentNum);
                        break;
                    
                    case 2:
                        result = Calculate_L(currentNum);
                        break;
                    
                    case 3:
                        result = Calculate_R(currentNum);
                        break;
                    
                    default:
                        break;
                }
                if (visited[result]) continue;

                tracker[result] = tracker[currentNum] + commands[i];
                visited[result] = 1;
                q.push(result);
            }
        }
        cout << tracker[b] << '\n';
    }
    return 0;
}