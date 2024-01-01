/*
 * @lc app=leetcode id=2261 lang=cpp
 *
 * [2261] K Divisible Elements Subarrays
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
    static void findSub(vector<int> &nums, int i, int j, unordered_set<string> &u)
    {
        for (int x = i; x <= j; x++)
        {
            string temp;
            for (int y = x; y <= j; y++)
            {
                temp += "$" + to_string(nums[y]);
                u.insert(temp);
            }
        }
    }
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int n = nums.size();
        int i = 0, j = 0, count = 0;
        unordered_set<string> u;

        while (j < n)
        {
            if (nums[j] % p == 0)
            {
                count++;
            }
            if (count > k)
            {
                findSub(nums, i, j - 1, u);
            }
            while (i < n && count > k)
            {
                if (nums[i] % p == 0)
                    count--;
                i++;
            }
            j++;
        }
        findSub(nums, i, n - 1, u);
        return u.size();
    }
};
// @lc code=end
