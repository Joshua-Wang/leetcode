/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file WordPattern.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/05/02 17:09:21
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class Solution {
    public:
        bool wordPattern(string pattern, string str) {
            vector<string> nums; // c++ dont have split function, boost does.
            stringstream ss(str);
            string temp;
            while (ss >> temp) {
                nums.push_back(temp);
            }
            map<char, int> pattern_map;
            map<string, int> str_map;
            int len1 = pattern.size();
            int len2 = nums.size();
            if (len1 != len2) {
                return false;
            }
            for (int i = 0; i < len1; i++) {
                if (pattern_map.count(pattern[i]) == 0) {
                    if (str_map.count(nums[i]) != 0) {
                        return false;
                    }
                } else {
                    if (str_map.count(nums[i]) == 0 || str_map[nums[i]] != pattern_map[pattern[i]]) {
                        return false;
                    }
                } 

                pattern_map[pattern[i]] = i;
                str_map[nums[i]] = i;
            }
            return true;
        }
};





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
