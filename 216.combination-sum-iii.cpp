/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int val, int index, int sum, int k, int n, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (k == index && sum == n)
        {
            ans.push_back(ds);
            return;
        }
        if (val > 9 || index > k)
            return;
        ds.push_back(val);
        solve(val + 1, index + 1, sum + val, k, n, ds, ans);
        ds.pop_back();
        solve(val + 1, index, sum, k, n, ds, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1, 0, 0, k, n, ds, ans);
        return ans;
    }
};
// @lc code=end
