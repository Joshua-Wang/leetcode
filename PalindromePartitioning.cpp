/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PalindromePartitioning.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/05/01 15:12:29
 * @brief 
 *  
 **/
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<vector<string> > res;
    public:
        // 一次AC，dfs的题真的挺有自信的；
        vector<vector<string> > partition(string s) {
            vector<string> tmp;
            search(s, 0, tmp);
            return res;
        }

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

        void search(string& s, int index, vector<string>& tmp) {
            if (index >= s.size()) {
                res.push_back(tmp);
                return ;
            }
            for (int i = index; i < s.size(); i++) {
                if (isPalindrome(s, index, i)) {
                    tmp.push_back(s.substr(index, i-index+1));
                    search(s, i+1, tmp);
                    tmp.pop_back();
                }
            }
        }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
