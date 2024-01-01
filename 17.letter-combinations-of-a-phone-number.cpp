/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, string> m;
    void makeCombination(int index, string digits, string &ds, vector<string> &ans)
    {
        if (index == digits.size())
        {
            ans.push_back(ds);
            return;
        }
        for (auto s : m[digits[index] - '0'])
        {
            ds += s;
            makeCombination(index + 1, digits, ds, ans);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        vector<string> ans;
        if (digits.size() == 0)
            return {};
        string ds = "";
        makeCombination(0, digits, ds, ans);
        return ans;
    }
};
// @lc code=end
