#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string formula;
int totalSize;

void Parenthesis(int order) {
    char a, b;
    if (order == 1)
        a = '*', b = '/';
    else
        a = '+', b = '-';
    
    for (int i = 0; i < totalSize; i++) {
        if (formula[i] == a || formula[i] == b) {
            int isIn = 0;

            for (int j = i - 1; j >= 0; j--) {
                if (formula[j] == ')')
                    isIn++;
                
                else if (formula[j] == '(')
                    isIn--;
                
                if (isIn == 0 && (isalpha(formula[j]) || formula[j] == '(')) {
                    formula.insert(j, "(");
                    break;
                }
            }
            isIn = 0;
            i++;
            totalSize++;
            for (int j = i + 1; j < totalSize; j++) {
                if (formula[j] == '(')
                    isIn++;
                
                else if (formula[j] == ')')
                    isIn--;
                
                if (isIn == 0 && (isalpha(formula[j]) || formula[j] == ')')) {
                    formula.insert(j + 1, ")");
                    break;
                }
            }
            totalSize++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> formula;

    vector<char> op;
    totalSize = formula.size();

    Parenthesis(1);
    Parenthesis(2);

    for (const auto& c : formula) {
        if (c == ')') {
            while (op.size()) {
                char popped = op.back();
                op.pop_back();

                if (popped == '(') break;
                cout << popped;
            }
        }
        else if (!isalpha(c))
            op.push_back(c);
        
        else
            cout << c;
    }
    return 0;
}