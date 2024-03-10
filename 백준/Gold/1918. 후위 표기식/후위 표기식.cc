#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string formula;
    vector<char> op;

    cin >> formula;
    int size = formula.size();

    for (int i = 0; i < size; i++) {
        if (formula[i] == '*' || formula[i] == '/') {
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
            size++;
            for (int j = i + 1; j < size; j++) {
                if (formula[j] == '(')
                    isIn++;
                
                else if (formula[j] == ')')
                    isIn--;
                
                if (isIn == 0 && (isalpha(formula[j]) || formula[j] == ')')) {
                    formula.insert(j + 1, ")");
                    break;
                }
            }
            size++;
        }
    }
    for (int i = 0; i < size; i++) {
        if (formula[i] == '+' || formula[i] == '-') {
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
            size++;
            for (int j = i + 1; j < size; j++) {
                if (formula[j] == '(')
                    isIn++;
                
                else if (formula[j] == ')')
                    isIn--;
                
                if (isIn == 0 && (isalpha(formula[j]) || formula[j] == ')')) {
                    formula.insert(j + 1, ")");
                    break;
                }
            }
            size++;
        }
    }
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