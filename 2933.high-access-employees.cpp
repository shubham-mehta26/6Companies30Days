/*
 * @lc app=leetcode id=2933 lang=cpp
 *
 * [2933] High-Access Employees
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<string> a, vector<string> b)
{
    if (a[0] == b[0])
        return stoi(a[1]) < stoi(b[1]);
    else
        return a[0] < b[0];
}

class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &v)
    {
        set<string> st;
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < v.size(); i++)
        {
            string person = v[i][0];
            int time = stoi(v[i][1]);
            if (i + 2 < v.size())
            {
                if ((v[i + 1][0] == person && stoi(v[i + 1][1]) < time + 100) &&
                    (v[i + 2][0] == person && stoi(v[i + 2][1]) < time + 100))
                {
                    st.insert(person);
                }
            }
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};
// @lc code=end
