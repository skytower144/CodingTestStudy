#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    string seats;
    cin >> seats;

    int cupHolders = 0;
    int people = 0;
    string temp = "";

    for (const auto c : seats) {
        if (c == 'L') {
            if (temp == "")
                temp += c;
            else {
                temp = "";
                cupHolders++;
            }
        }
        else
            cupHolders++;
    
        people++;
    }
    cupHolders++;
    cout << min(people, cupHolders);
    return 0;
}