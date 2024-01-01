/*
 * @lc app=leetcode id=2375 lang=cpp
 *
 * [2375] Construct Smallest Number From DI String
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
    string ans = "";

    void solve(int i, int val, char prev, string &s, string &ds, vector<int> &visited)
    {
        if (ds.length() == s.length() + 1)
        {
            ans = ds;
            return;
        }
        if (prev == '*')
        {
            for (int j = 1; j <= 9; j++)
            {
                char ch = j + '0';
                visited[j] = 1;
                ds += ch;
                solve(i + 1, j, s[i], s, ds, visited);
                ds.pop_back();
                visited[j] = 0;
            }
        }
        else if (prev == 'I')
        {
            for (int j = val + 1; j <= 9; j++)
            {
                if (visited[j] == 0 && ans.length() == 0)
                {
                    char ch = j + '0';
                    visited[j] = 1;
                    ds += ch;
                    solve(i + 1, j, s[i], s, ds, visited);
                    ds.pop_back();
                    visited[j] = 0;
                }
            }
        }
        else
        {
            for (int j = val - 1; j >= 1; j--)
            {
                if (visited[j] == 0 && ans.length() == 0)
                {
                    char ch = j + '0';
                    visited[j] = 1;
                    ds += ch;
                    solve(i + 1, j, s[i], s, ds, visited);
                    ds.pop_back();
                    visited[j] = 0;
                }
            }
        }
    }

    string smallestNumber(string pattern)
    {
        vector<int> visited(10, 0);
        string ds = "";
        solve(0, -1, '*', pattern, ds, visited);
        return ans;
    }
};
// @lc code=end
