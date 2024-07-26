#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

struct MusicInfo {
    int length;
    string name;
    vector<string> melody;
};

vector<string> CreateNoteList(string melody)
{
    vector<string> noteList;
    int melodyLength = melody.size();
    int i = 0;
    
    while (i < melodyLength)
    {
        string note = "";
        note += melody[i];
        
        if (i < melodyLength - 1 && melody[i + 1] == '#')
        {
            note += '#';
            i++;
        }
        i++;
        noteList.push_back(note);
    }
    return noteList;
}

int GetMusicLength(string timeString)
{
    int hour = stoi(timeString.substr(0, 2));
    int minutes = stoi(timeString.substr(3, 2));
    return hour * 60 + minutes;
}

MusicInfo ParseMusicInfo(string info)
{
    MusicInfo newInfo;
    stringstream ss(info);
    string buffer;
    
    int startTime, endTime;
    int type = 0;
    
    while (getline(ss, buffer, ','))
    {
        switch(type)
        {
            case 0:
                startTime = GetMusicLength(buffer);
                break;
            
            case 1:
                endTime = GetMusicLength(buffer);
                break;
            
            case 2:
                newInfo.name = buffer;
                break;
            
            case 3:
                newInfo.melody = CreateNoteList(buffer);
                break;
        }
        type++;
    }
    newInfo.length = endTime - startTime;
    return newInfo;
}

bool IsMusicMatch(vector<string> heardMusicNotes, MusicInfo musicInfo)
{
    int heardNoteCount = heardMusicNotes.size();
    int musicMelodySize = musicInfo.melody.size();
    
    for (int i = 0; i < min(musicMelodySize, musicInfo.length); i++)
    {
        bool isMatch = true;
        for (int j = 0; j < heardNoteCount; j++)
        {
            if (heardMusicNotes[j] != musicInfo.melody[(i + j) % musicMelodySize])
            {
                isMatch = false;
                break;
            }
        }
        if (isMatch)
            return true;
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<MusicInfo> musicList;
    vector<string> heardMusicNotes = CreateNoteList(m);
    MusicInfo longestMusic;

    for (auto info : musicinfos)
        musicList.push_back(ParseMusicInfo(info));
    
    for (auto music : musicList)
    {
        if (IsMusicMatch(heardMusicNotes, music))
        {
            if (answer == "(None)" || longestMusic.length < music.length)
            {
                longestMusic = music;
                answer = longestMusic.name;
            }
        }
    }
    return answer;
}