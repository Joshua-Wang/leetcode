/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file word-break.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/03/30 19:11:15
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        // basic dfs search, TIME LIMIT EXCED;
        bool wordBreak(string s, unordered_set<string>& wordDict) {
            int len = s.size();
            return search(s, 0, wordDict);
        }

        bool search(string s, int begin, unordered_set<string>& wordDict) {
            if (begin >= s.size()) {
                return true;
            }
            for (int i = begin+1; i < s.size(); i++) {
                if (wordDict.count(s.substr(begin, i-begin))) {
                    if (search(s, i, wordDict)) {
                        return true;
                    }
                }
            }
            return false;
        }
        
        bool wordBreak(string s, unordered_set<string>& wordDict) {
            int len = s.size();
            bool dp[len] = {false};
            dp[0] = wordDict.count(s.substr(0,1)) > 0 ? true : false;
            for (int i = 1; i < len; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] && wordDict.count(s.substr(j+1, i-j)) > 0) {
                        dp[i] = true;
                        break;
                    }
                } 
                if (dp[i] == false && wordDict.count(s.substr(0, i+1))) { // at first, here s.substr(0, i) carsed error.
                    dp[i] = true;
                }
            }
            return dp[len-1]; 
        }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
