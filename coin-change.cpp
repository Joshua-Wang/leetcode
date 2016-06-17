/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file coin-change.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/09 12:23:56
 * @brief 
 *  
 **/


#include <vector>
#include <set>
#include <math.h>
#include <iostream>

using namespace std;
// O(n*n*log(n)) 可以优化到O(n*m)
class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int len = coins.size();
            int dp[amount+1];
            set<int> coin_set;
            for (int i = 0; i < len; i++) {
                coin_set.insert(coins[i]);
            }
            int max_value = 9999999;
            memset(dp, max_value, sizeof(int)*(amount+1));
            dp[0] = 0;
            for (int i = 1; i <= amount; i++) {
                if (coin_set.count(i) == 1) {
                    dp[i] = 1;
                    continue;
                }
                int value = max_value;
                for (int j = 0; j < i; j++) {
                    if (dp[j] != max_value && coin_set.count(i-j) != 0) {
                        value = min(value, dp[j]+1); 
                    }
                }
                dp[i] = value;
            }
            if (dp[amount] == max_value) {
                return -1;
            } else {
                return dp[amount];
            }
        }

        // 第一次提交的方法用了额外空间还超时了，还是有很多优化空间的呀；
        int coinChange2(vector<int>& coins, int amount) {
            int len = coins.size();
            int dp[amount+1];
            int max_value = 9999999;
            memset(dp, max_value, sizeof(int)*(amount+1));
            dp[0] = 0;
            for (int i = 1; i <= amount; i++) {
                int value = max_value;
                for (int j = 0; j < len; j++) {
                    if (i-coins[j] >= 0 && dp[i-coins[j]] != max_value) {
                        value = min(value, dp[i-coins[j]] + 1);
                    } 
                }
                dp[i] = value;

            }
            if (dp[amount] == max_value) {
                return -1;
            } else {
                return dp[amount];
            }
        }
};

int main() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(5);

    vector<int> v2;
    v2.push_back(2);

    Solution s;
    
    cout << s.coinChange2(v1, 11) << endl;
    cout << s.coinChange2(v2, 3) << endl;

}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
