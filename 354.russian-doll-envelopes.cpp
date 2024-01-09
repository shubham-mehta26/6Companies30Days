/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
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
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), [&](const vector<int> &a, const vector<int> &b)
             {
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0]; });
        vector<int> v;
        for (auto e : envelopes)
        {
            if (!v.size() || v.back() < e[1])
                v.push_back(e[1]);
            else
            {
                int index = lower_bound(v.begin(), v.end(), e[1]) - v.begin();
                v[index] = e[1];
            }
        }
        return v.size();
    }
};
// @lc code=end
