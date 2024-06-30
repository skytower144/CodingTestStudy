#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> fileIndexes;

string ToLower(string& tag)
{
    for (auto& c : tag)
    {
        if (c >= 'A' && c <= 'Z')
            c += 'a' - 'A';
    }
    return tag;
}

vector<string> SplitTag(string file)
{
    vector<string> tags;
    int numStart = -1, extensionStart = file.size();
    
    for (int i = 0; i < file.size(); i++)
    {
        char c = file[i];
        if (numStart < 0 && c >= '0' && c <= '9')
            numStart = i;
        
        else if (numStart > 0 && (c < '0' ||  c > '9'))
        {
            extensionStart = i;
            break;
        }
    }
    string name = file.substr(0, numStart);
    string head = file.substr(numStart, extensionStart - numStart);
    
    tags.push_back(ToLower(name));
    tags.push_back(ToLower(head));
    return tags;
}
bool compare(string fileA, string fileB)
{
    vector<string> aTags = SplitTag(fileA);
    vector<string> bTags = SplitTag(fileB);
    
    if (aTags[0] < bTags[0])
        return true;
    
    else if (aTags[0] > bTags[0])
        return false;
    
    int aNum = stoi(aTags[1]);
    int bNum = stoi(bTags[1]);
    
    if (aNum < bNum)
        return true;
    
    else if (aNum > bNum)
        return false;
    
    return fileIndexes[fileA] < fileIndexes[fileB];
}
vector<string> solution(vector<string> files) {
    for (int i = 0; i < files.size(); i++)
        fileIndexes[files[i]] = i;
        
    sort(files.begin(), files.end(), compare);
    return files;
}