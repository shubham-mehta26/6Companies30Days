/*
 * @lc app=leetcode id=2327 lang=cpp
 *
 * [2327] Number of People Aware of a Secret
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
    const int mod = 1e9 + 7;
    long solve(int n, int delay, int forget, vector<int> &dp)
    {
        if (!n)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        long ans = 1;
        for (int i = delay; i < forget; i++)
        {
            if (n - i > 0)
                ans = (ans + solve(n - i, delay, forget, dp)) % mod;
        }
        return dp[n] = ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<int> dp(n + 1, -1);
        return (solve(n, delay, forget, dp) - solve(n - forget, delay, forget, dp) + mod) % mod;
    }
};
// @lc code=end
