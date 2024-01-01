/*
 * @lc app=leetcode id=2526 lang=cpp
 *
 * [2526] Find Consecutive Integers from a Data Stream
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
// Author: wind2002

class DataStream
{
public:
    int value, k, valueCount = 0;
    DataStream(int value, int k)
    {
        this->value = value;
        this->k = k;
    }

    bool consec(int num)
    {
        if (num == value)
            valueCount++;
        else
            valueCount = 0;
        return valueCount >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
// @lc code=end
