#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ALL 1048575

using namespace std;

int Add(int result, int num) {
    return result | (1 << (num - 1));
}
int Remove(int result, int num) {
    int filter = ~(1 << (num - 1));
    return result & filter;
}
bool Check(int result, int num) {
    return result & (1 << (num - 1));
}
int Toggle(int result, int num) {
    return result ^ (1 << (num - 1));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int m, num, result = 0;
    string command;

    cin >> m;
    cin.ignore();

    while (m--) {
        cin >> command;

        if (command == "all")
            result = ALL;
        
        else if (command == "empty")
            result = 0;

        else {
            cin >> num;

            if (command == "add")
                result = Add(result, num);

            else if (command == "remove")
                result = Remove(result, num);

            else if (command == "check")
                cout << Check(result, num) << '\n';

            else if (command == "toggle")
                result = Toggle(result, num);
        }
    }
    return 0;
}