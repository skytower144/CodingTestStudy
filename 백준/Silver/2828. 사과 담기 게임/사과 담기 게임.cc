#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, j;
    cin >> n >> m >> j;

    int movedDistance = 0;
    int basketFront = 0;
    int basketEnd = m - 1;
    int pos, posFromFront, posFromEnd;

    for (int i = 0; i < j; i++) {
        cin >> pos;
        if (n < pos || (basketFront <= pos - 1 && basketEnd >= pos - 1))
            continue;

        pos--;
        posFromFront = pos - basketFront;
        posFromEnd = pos - basketEnd;

        if (abs(posFromFront) < abs(posFromEnd)) {
            basketFront += posFromFront;
            basketEnd += posFromFront;
            movedDistance += abs(posFromFront);
        }
        else {
            basketFront += posFromEnd;
            basketEnd += posFromEnd;
            movedDistance += abs(posFromEnd);
        }
        // cout << "front : " << basketFront << " end : " << basketEnd << endl;
    }
    cout << movedDistance;
    return 0;
}
/*
     @
         @
 @
| | | | | |
 _
*/