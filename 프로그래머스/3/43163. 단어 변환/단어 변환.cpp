#include <string>
#include <vector>

using namespace std;

int answer = 0;
string Target;

bool CanChange(string& a, string& b)
{
    int diff = 0;
    
    for (int i = 0; i < a.size(); i++)
        diff += a[i] != b[i];
    
    return diff == 1;
}

void GetSolution(vector<string>& words, vector<bool>& visited, string current, int depth)
{
    for (int i = 0; i < words.size(); i++)
    {
        if (visited[i])
            continue;
        
        if (!CanChange(current, words[i]))
            continue;
        
        if (Target == words[i])
        {
            answer = depth + 1;
            return;
        }
        
        visited[i] = true;
        GetSolution(words, visited, words[i], depth + 1);
    }
}

int solution(string begin, string target, vector<string> words) {
    Target = target;
    
    bool flag = false;
    
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == target)
        {
            flag = true;
            break;
        }
    }
    
    if (!flag)
        return 0;
    
    vector<bool> visited(words.size(), false);
    GetSolution(words, visited, begin, 0);
    
    return answer;
}