#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

void CreateGiftSheet(unordered_map<string, int>& friendMap, vector<string>& gifts, vector<vector<int>>& giftSheet);
void InitGiftPoints(vector<string>& friends, vector<int>& giftPoints, vector<vector<int>>& giftSheet);
int GetGiftPoint(int person, int totalPeople, vector<vector<int>>& giftSheet);

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    vector<int> giftPoints;
    vector<vector<int>> giftSheet;
    unordered_map<string, int> friendMap;
    vector<int> futureGifts = vector<int>(friends.size(), 0);
    
    for (int i = 0; i < friends.size(); i++)
        friendMap[friends[i]] = i;
    
    CreateGiftSheet(friendMap, gifts, giftSheet);
    InitGiftPoints(friends, giftPoints, giftSheet);

    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = i; j < friends.size(); j++)
        {
            if (i == j) continue;
            
            if ((!giftSheet[i][j] && !giftSheet[j][i]) || giftSheet[i][j] == giftSheet[j][i])
            {
                if (giftPoints[i] > giftPoints[j])
                    futureGifts[i]++;
            
                else if (giftPoints[i] < giftPoints[j])
                    futureGifts[j]++;
            }
            else
            {
                if (giftSheet[i][j] > giftSheet[j][i])
                    futureGifts[i]++;
                else 
                    futureGifts[j]++;
            }
        }
    }
    for (int i = 0; i < futureGifts.size(); i++)
    {
        if (answer < futureGifts[i])
            answer = futureGifts[i];
    }
    return answer;
}
void CreateGiftSheet(unordered_map<string, int>& friendMap, vector<string>& gifts, vector<vector<int>>& giftSheet)
{
    giftSheet = vector<vector<int>>(friendMap.size(), vector<int>(friendMap.size(), 0));
    for (int i = 0; i < gifts.size(); i++)
    {
        stringstream ss(gifts[i]);
        string giver, receiver;
        
        while (ss >> giver >> receiver)
            giftSheet[friendMap[giver]][friendMap[receiver]]++;
    }
}
void InitGiftPoints(vector<string>& friends, vector<int>& giftPoints, vector<vector<int>>& giftSheet)
{
    giftPoints = vector<int>(friends.size(), 0);
    for (int i = 0; i < friends.size(); i++)
        giftPoints[i] = GetGiftPoint(i, friends.size(), giftSheet);
}
int GetGiftPoint(int person, int totalPeople, vector<vector<int>>& giftSheet)
{
    int gave = 0, received = 0;
    for (int i = 0; i < totalPeople; i++)
    {
        if (i == person)
        {
            for (int j = 0; j < totalPeople; j++)
                gave += giftSheet[person][j];
            continue;
        }
        received += giftSheet[i][person];
    }
    return gave - received;
}