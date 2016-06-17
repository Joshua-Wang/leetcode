/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file RangeSumQueryMutable.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/05/08 21:49:10
 * @brief 
 *  
 **/
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class NumArray {
    private:
        vector<int> v_sum;
    public:
        NumArray(vector<int> &nums) {
            int len = nums.size();
            if (len == 0) {
                return ;
            }
            v_sum.push_back(0);
            for (int i = 1; i <= len; i++) {
                v_sum.push_back(v_sum[i-1] + nums[i-1]);
            }
        }

        void update(int i, int val) {
            int offset = val - (v_sum[i+1] - v_sum[i]);
            for (int x = i+1; x < v_sum.size(); x++) {
                v_sum[x] += offset;
            }
        }

        int sumRange(int i, int j) {
            return v_sum[j+1] - v_sum[i];
        }
};

int main() {
    int array[] = {1,3,5};
    vector<int> v(array, array+3);
    NumArray numArray(v);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
