/*
 * @lc app=leetcode id=1765 lang=cpp
 *
 * [1765] Map of Highest Peak
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
// Author: wind2002

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    { // MultiSource bfs
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    q.push({i, j});
                    isWater[i][j] = 0;
                }
                else
                    isWater[i][j] = -1;
            }
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int height = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int level = 0; level < size; level++)
            {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];
                    if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && isWater[new_x][new_y] == -1)
                    {
                        isWater[new_x][new_y] = height;
                        q.push({new_x, new_y});
                    }
                }
            }
            height++;
        }
        return isWater;
    }
};
// @lc code=end
