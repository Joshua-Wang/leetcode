/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file containsNearbyDuplicate.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/03 14:35:21
 * @brief 
 *  
 **/
#include <vector>
#include <map>
#include <stdio.h>

// 一次AC的能力太差了, 这么简单的题做了好多遍；
// 凡是找重复的数组的题都想想map , set ；
// map.insert() 如果数组中已有的话是不会更新的，必须map[key] = newvalue;
using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            map<int, int> mymap;
            for (int i = 0; i < nums.size(); i++) {
                if (mymap.count(nums[i]) != 0) {
                    int index = mymap[nums[i]];
                    if (i - index <= k) {
                        return true;
                    } else {
                        mymap[nums[i]] = i;
                    }
                } else {
                    mymap.insert(pair<int, int>(nums[i], i));
                }

            }
            return false;

        }
};

int main () {
    vector<int> test;
    test.push_back(1);
    test.push_back(0);
    test.push_back(1);
    test.push_back(1);
    Solution s;
    if (s.containsNearbyDuplicate(test, 1)) {
        printf("Yes");
    }
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
