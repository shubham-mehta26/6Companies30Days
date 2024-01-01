/*
 * @lc app=leetcode id=2400 lang=cpp
 *
 * [2400] Number of Ways to Reach a Position After Exactly k Steps
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
    const int offset = 1000;
    int solve(int start, int end, int k, vector<vector<ll>> &dp)
    {
        if (k < 0)
            return 0;
        if (k == 0 && start == end)
            return 1;
        if (dp[start + offset][k] != -1)
            return dp[start + offset][k];
        ll back = 0, front = 0;
        back = (back + solve(start - 1, end, k - 1, dp)) % mod;
        front = (front + solve(start + 1, end, k - 1, dp)) % mod;
        return dp[start + offset][k] = (back + front) % mod;
    }
    int numberOfWays(int s, int e, int k)
    {
        vector<vector<ll>> dp(4000, vector<ll>(4000, -1));
        return solve(s, e, k, dp);
    }
};
// @lc code=end
