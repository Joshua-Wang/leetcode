/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file uniq-bst.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/17 20:13:58
 * @brief 
 *  
 **/

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
    public:
        int numTrees(int n) {
            int dp[n+1];
            memset(dp, 0, sizeof(int) * (n+1));
            dp[0] = 1;
            for (int i = 1; i <= n; i++) {
                int temp = 0;
                for (int j = 0; j < i; j++) {
                    temp += dp[j] * dp[i-j-1];
                }
                dp[i] = temp;
            }
            return dp[n];
        }
};




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
