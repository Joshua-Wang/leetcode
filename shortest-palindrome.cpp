/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file shortest-palindrome.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/20 09:42:00
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s, int index) {
            int left = 0;
            int right = index;
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
        string shortestPalindrome2(string s) {
            int len = s.size();
            int index = len-1;
            for (; index >= 0; index--) {
                if (isPalindrome(s, index)) {
                    break;
                }
            }
            ostringstream oss;
            for (int j = len-1; j >= index+1; j--) {
                oss << s[j]; 
            }
            oss << s;
            return oss.str();

        }
       
        // s_reverse = s.reverse();
        // new_s = s+s_reverse;
        // 利用KMP求new_s的最长公共前缀；
        string shortestPalindrome(string s) {
            
        }
};

int main() {
    string test = "cbca";
    Solution s;
    cout << s.shortestPalindrome(test) << endl;
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
