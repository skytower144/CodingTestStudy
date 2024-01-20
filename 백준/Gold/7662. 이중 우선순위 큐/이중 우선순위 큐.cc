#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int k, num;
        char command;
        map<int, int> numMap;
        int size;

        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> command >> num;

            switch (command) {
                case 'I':
                    numMap[num]++;
                    break;
                
                case 'D':
                    size = numMap.size();
                    if (!size) continue;

                    if (num == 1) {
                        auto it = numMap.end();
                        it--;
                        if (it->second > 1)
                            it->second--;
                        else
                            numMap.erase(it);
                    }
                    else {
                        if (numMap.begin()->second > 1)
                            numMap.begin()->second--;
                        else
                            numMap.erase(numMap.begin());
                    }
                    break;
                
                default:
                    break;
            }
        }
        if (!numMap.size())
            cout << "EMPTY\n";
        else {
            auto beginIt = numMap.begin();
            auto endIt = numMap.end();
            endIt--;
            cout << endIt->first << " " << beginIt->first << '\n';
        }
    }
    return 0;
}