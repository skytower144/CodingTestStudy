#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int index;
    string word;

    cin >> word;
    cin >> index;
    
    cout << word[index - 1];
    return 0;
}