/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file LargestRectangleinHistogram.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/20 09:43:58
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

class Solution {
    public:
        // Time Limit Excede.
        int largestRectangleArea2(vector<int>& heights) {
            int begin = 0;
            int end = heights.size() - 1;
            int res = 0;
            while (begin < end) {
                int minHeight = INT_MAX;
                for (int i = begin; i <= end; i++) {
                    minHeight = min(minHeight, heights[i]);
                }
                res = max(res, minHeight*(end-begin+1));
                if (begin < end) {
                    begin++;
                } else {
                    end--;
                }
            }
            return res;
        }

        // Stack based solution.
        // stack 里面存的是索引
        // 这题从网上抄的，关键是计算单调增矩形面积的方法
        int largestRectangleArea(vector<int>& heights) {
            stack<int> ss;
            heights.push_back(0);
            int res = 0;
            int i = 0;
            while (i < heights.size()) {
                if (ss.empty() || heights[ss.top()] <= heights[i]) {
                    ss.push(i);
                    i++;
                } else {
                    int tmp = ss.top();
                    ss.pop();
                    res = max(res, heights[tmp] * (ss.empty() ? i : i - ss.top() - 1));
                }
            }
            return res; 
            
        }

};



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
