#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, unordered_map<string, int>> giftMap;
    unordered_map<string, int> giftIndex;
    unordered_map<string, int> reservedGifts;
    
    for (const auto& gift : gifts)
    {
        stringstream ss(gift);
        string giver, receiver;
        
        ss >> giver >> receiver;
        giftMap[giver][receiver]++;
        
        giftIndex[giver]++;
        giftIndex[receiver]--;
    }
    
    for (const auto& giver : friends)
    {
        for (const auto& receiver : friends)
        {
            if (giver == receiver)
                continue;
            
            bool recordExists = (giftMap[giver].count(receiver) > 0) || (giftMap[receiver].count(giver));

            if (giftMap[giver][receiver] > giftMap[receiver][giver])
                reservedGifts[giver]++;
            
            else if (giftMap[giver][receiver] == giftMap[receiver][giver] || !recordExists)
            {
                if (giftIndex[giver] > giftIndex[receiver])
                    reservedGifts[giver]++;
            }
        }
        
        answer = max(answer, reservedGifts[giver]);
    }
    
    return answer;
}