/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file maxProduct.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/10 16:51:37
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// 算法一开始就是错的，设计完算法之后要多写写测试用例，自己随便列举一些，很快就能发现问题
// 埋头写完发现全都错了 
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int len = nums.size();
            if (len == 0) return 0;
            int dp[len];
            const int MAX_VALUE = 0xFFFFFFFF;
            memset(dp, MAX_VALUE, len * sizeof(int));
            dp[0] = nums[0];
            int res = MAX_VALUE * -1;
            for (int i = 1; i < len; i++) {
                if (dp[i-1] > 0 && nums[i] > 0) {
                    dp[i] = dp[i-1] * nums[i];
                    continue;
                }

                if (dp[i-1] < 0 && nums[i] < 0) {
                    dp[i] = dp[i-1] * nums[i];
                    continue;
                }

                if (dp[i-1] == 0 && nums[i] < 0) {
                    dp[i] = dp[i-1] * nums[i];
                    continue;
                }

                if (dp[i-1] == 0 && nums[i] > 0) {
                    dp[i] = nums[i];
                    continue;
                }
                dp[i] = nums[i];
            }
            for (int i = 0; i < len; i++) {
                res = max(res, dp[i]);
            }
            return res;

        }
};

int main() {
    vector<int > v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(-2);
    v1.push_back(4);

    Solution s;
    cout << s.maxProduct(v1) << endl;

}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
