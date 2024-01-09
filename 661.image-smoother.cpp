/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
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
    int solve(vector<vector<int>> &img, int row, int col, int m, int n)
    {
        int sum = 0, cell = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int x = row + i;
                int y = col + j;
                if (x >= 0 && x < m && y >= 0 && y < n)
                {
                    sum += img[x][y];
                    cell++;
                }
            }
        }
        return sum / cell;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int row = img.size(), col = img[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ans[i][j] = solve(img, i, j, row, col);
            }
        }
        return ans;
    }
};
// @lc code=end
