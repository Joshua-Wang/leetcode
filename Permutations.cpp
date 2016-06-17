/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file Permutations.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/09 13:29:13
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>


// ¾ÃÎ¥µÄÒ»´ÎAC

using namespace std;

class Solution {
    private:
        int used[10000];
    public:
        vector<vector<int> > permute(vector<int>& nums) {
            memset(used, 0, sizeof(int)*10000);
            vector<vector<int> > res;
            vector<int> temp;
            dfs(res, nums, temp, 0);
            return res;
        }

        void dfs(vector<vector<int> >& res, vector<int>& nums, vector<int>& temp, int index) {
            if (index == nums.size()) {
                res.push_back(temp);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (!used[i]) {
                    used[i] = 1;
                    temp.push_back(nums[i]);
                    dfs(res, nums, temp, index+1);
                    used[i] = 0;
                    temp.pop_back();
                }
            } 
        }
};

int main() {
    Solution s;

}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
