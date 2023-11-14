#include <string>
#include <vector>

using namespace std;

char allowedSymbols[13] = {'0','1','2','3','4','5','6','7','8','9','-', '_', '.'};

bool isSymbolAllowed(char c) {
    for (const auto symbol : allowedSymbols) if (symbol == c) return true;
    return false;
}

string solution(string new_id) {
    string modified_id = new_id;
    string temp = "";
    
    // Phase 1, 2
    for (auto& c : modified_id) {
        c = tolower(c);
        if (isalpha(c) || isSymbolAllowed(c)) temp += c;
    }
    modified_id = temp;
    temp = "";
    
    // Phase 3
    for (int i = 0; i < modified_id.size(); i++) {
        if (i != 0 && modified_id[i -1] == modified_id[i] && modified_id[i] == '.') continue;
        temp += modified_id[i];
    }
    modified_id = temp;
    temp = "";
    
    // Phase 4
    int start = 0, end = modified_id.size() - 1;
    
    if (modified_id[0] == '.') start++;
    if (modified_id.size() && modified_id.back() == '.') end--;
    modified_id = modified_id.substr(start, end - start + 1);
    
    // Phase 5, 6, 7
    if (!modified_id.size())
        modified_id = "a";
    
    else if (modified_id.size() >= 16) {
        int cutSize = 15;
        
        if (modified_id[14] == '.') cutSize--;
        modified_id = modified_id.substr(0, cutSize);
    }
    if (modified_id.size() <= 2)
        while (modified_id.size() < 3) modified_id += modified_id.back();
    
    return modified_id;
}