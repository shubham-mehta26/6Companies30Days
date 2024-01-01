/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "bits/stdc++.h"
using namespace std;
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Author: wind2002

class Solution
{
public:
    tuple<int, int, int, int> dfs(TreeNode *r, int &ans)
    {
        if (!r)
            return {1, 0, INT_MAX, INT_MIN};

        auto [leftisBst, leftSum, leftMin, leftMax] = dfs(r->left, ans);
        auto [rightisBst, rightSum, rightMin, rightMax] = dfs(r->right, ans);

        if (leftisBst == 0 || rightisBst == 0)
            return {0, 0, 0, 0};
        if (leftMax >= r->val || rightMin <= r->val)
            return {0, 0, 0, 0};

        int sum = leftSum + r->val + rightSum;
        ans = max(sum, ans);
        int minimum = min(r->val, leftMin);
        int maximum = max(r->val, rightMax);
        return {1, sum, minimum, maximum};
    }

    int maxSumBST(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
// @lc code=end
