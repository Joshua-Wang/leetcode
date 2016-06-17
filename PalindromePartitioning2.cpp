/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PalindromePartitioning2.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/05/01 16:46:22
 * @brief 
 *  
 **/

#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s, int left, int right) {
            while (right >= left) {
                if (s[right] != s[left]) {
                    return false;
                }
                right--;
                left++;
            }
            return true;
        }
        // TLE
        int minCut2(string s) {
            int len = s.size();
            int dp[len]; 
            memset(dp, -1, sizeof(int) * len);
            dp[0] = 0; 
            for (int i = 1; i < len; i++) {
                if (isPalindrome(s, 0, i)) {
                    dp[i] = 0;
                } else {
                    int temp = INT_MAX;
                    for (int j = 0; j < i; j++) {
                        if (dp[j] != -1 && isPalindrome(s, j+1, i)) {
                            temp  = min(temp, dp[j] + 1);
                        } 
                        dp[i] = temp;
                    }
                }
            }
            return dp[len-1];
        }
       
        // 判断是否是回文的方法可以去掉；
        // 用dp数组来判断是否是回文的方法： dp[i][j] = (s[i] == s[j] && ((i-j<2) || dp[i+1][j-1]))
        // 所以这种方式必须从后往前算；
        int minCut(string s) {
            
        }
};

int main() {
    string str = "accabbdccd";
    Solution s;
    cout << s.minCut(str) << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
