#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> want;
vector<pair<int, int>> seatPos;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int content[5] = { 0, 1, 10, 100, 1000 };
int n, total;

int GetId(pair<int, int> pos)
{
    return pos.first * 100 + pos.second;
}

pair<int, int> GetPos(int id)
{
    return { id / 100, id % 100 };
}

pair<int, int> FindSmallestCol(vector<pair<int, int>>& cd)
{
    int minCol = n;
    pair<int, int> singleCandidate;

    for (int i = 0; i < cd.size(); i++)
    {
        if (minCol > cd[i].first)
        {
            minCol = cd[i].first;
            singleCandidate = cd[i];
        }
    }

    return singleCandidate;
}

pair<int, int> FindSmallestRow(vector<pair<int, int>>& cd)
{
    int minRow = n;
    vector<pair<int, int>> candidates;

    for (int i = 0; i < cd.size(); i++)
    {
        if (minRow >= cd[i].second)
        {
            if (minRow > cd[i].second)
            {
                minRow = cd[i].second;
                candidates.clear();
            }

            candidates.push_back(cd[i]);
        }
    }

    if (candidates.size() > 1)
        return FindSmallestCol(candidates);

    return candidates[0];
}

pair<int, int> FindMostVacant(vector<pair<int, int>>& cd)
{
    int maxCount = -1;
    vector<pair<int, int>> candidates;

    for (int i = 0; i < cd.size(); i++)
    {
        int count = 0;

        for (int j = 0; j < 4; j++)
        {
            int nx = cd[i].first + dx[j];
            int ny = cd[i].second + dy[j];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (grid[ny][nx] == 0)
                count++;
        }

        if (maxCount <= count)
        {
            if (maxCount < count)
            {
                maxCount = count;
                candidates.clear();
            }

            candidates.push_back(cd[i]);
        }
    }

    if (candidates.size() > 1)
        return FindSmallestRow(candidates);

    return candidates[0];
}

pair<int, int> FindSeat(int current)
{
    unordered_map<int, int> seatMap;

    for (int person : want[current])
    {
        if (seatPos[person].first == -1)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = seatPos[person].first + dx[i];
            int ny = seatPos[person].second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (grid[ny][nx] > 0)
                continue;

            seatMap[GetId({nx, ny})]++;
        }
    }

    int maxCount = -1;
    vector<pair<int, int>> candidates;

    if (seatMap.size() == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    candidates.push_back({ j, i });
            }
        }
        return FindMostVacant(candidates);
    }

    for (const auto& kv : seatMap)
    {
        if (maxCount <= kv.second)
        {
            if (maxCount < kv.second)
            {
                maxCount = kv.second;
                candidates.clear();
            }

            candidates.push_back(GetPos(kv.first));
        }
    }

    if (candidates.size() > 1)
        return FindMostVacant(candidates);

    return candidates[0];
}

int GetAnswer()
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            unordered_map<int, bool> wantMap;
            int current = grid[i][j];
            int count = 0;

            for (int k = 0; k < want[current].size(); k++)
                wantMap[want[current][k]] = true;

            for (int k = 0; k < 4; k++)
            {
                int nx = j + dx[k];
                int ny = i + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                int num = grid[ny][nx];

                if (wantMap.count(num) > 0)
                    count++;
            }

            answer += content[count];
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    total = n * n;

    grid = vector<vector<int>>(n, vector<int>(n, 0));
    want = vector<vector<int>>(total + 1);
    seatPos = vector<pair<int, int>>(total + 1, {-1, -1});

    int current, num;

    for (int i = 0; i < total; i++)
    {
        cin >> current;
        
        for (int j = 0; j < 4; j++)
        {
            cin >> num;
            want[current].push_back(num);
        }

        pair<int, int> pos = FindSeat(current);

        grid[pos.second][pos.first] = current;
        seatPos[current] = pos;
    }

    int answer = GetAnswer();
    cout << answer;

    return 0;
}