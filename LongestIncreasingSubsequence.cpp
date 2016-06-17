/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
/**
 * @file LongestIncreasingSubsequence.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/08 09:19:39
 * @brief 
 *  
 **/

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

// 其实也是dp， 自己最开始的时候想的是 dp[i] 和 dp[i-1]的关系，其实不对，跟i-1都有关系
// dp[i] = max{dp[j]+1 , dp[i]} , j>=0 && j<i && nums[j] < nums[i]
// 多用dp来解决问题，可能跟前面多个有关，不仅是前一个；

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int len = nums.size();
            if (len == 0) return 0;
            int dp[len];
            memset(dp, 0, sizeof(int)*len);
            dp[0] = 1;
            int res = 1;
            for (int i = 1; i < len; i++) {
                int temp = 0;
                for (int j = 0; j < i; j ++) {
                    if (nums[j] < nums[i]) {
                        temp = max(temp, dp[j]+1);
                    }
                }
                dp[i] = (temp == 0) ? 1 : temp;
                res = max(res, dp[i]);
            }
            return res;
        }
};

int main() {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(9);
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(7);
    v1.push_back(101);
    v1.push_back(18);
    Solution s;
    cout << s.lengthOfLIS(v1) << endl;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
