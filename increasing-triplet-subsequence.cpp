/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file increasing-triplet-subsequence.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/17 20:42:23
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;


// 不确定这些机器的int是多少位的，就要用INT_MAX;
class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            const int MAX_VALUE = INT_MAX;
            int minValue = MAX_VALUE, lessMinValue = MAX_VALUE;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= minValue) {
                    minValue = nums[i];
                } else if (nums[i] <= lessMinValue) {
                    lessMinValue = nums[i];
                } else {
                    return true;
                }
            }
            return false;
        }
};





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
