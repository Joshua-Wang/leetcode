/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file missing-numbers.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/02 10:28:33
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int len = nums.size();
            int dp[len+1]; // ��ʼ���������ֵ������ģ������ʼ���� 
            memset(dp, 0, sizeof(int)*(len+1)); //memset(dp, 0, sizeof(int))), ���ݱ�������ͬ��д����ͬ��leetcode����Ҫд��memset(dp, 0, sizeof(int)*(len+1)) ���У�
            for(int i = 0; i < len; i++) {
                dp[nums[i]] = 1;
            }   
            for (int i = 0; i < len+1; i++) {
                if (!dp[i]) {
                    return i;
                }   
            }   
        }   
};


int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(0);
    Solution s;
    cout << s.missingNumber(a) << endl;
}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
