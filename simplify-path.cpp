/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file simplify-path.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/03/28 22:04:35
 * @brief 
 *  
 **/

#include <string>
#include <stack>
#include <iostream>

using namespace std;

// after wrong for so many times. I got AC finally.

class Solution {
    public:
        string simplifyPath(string path) {
            if (path.size() == 0) {
                return "";
            }
            if (path == "/") {
                return "/";
            }
            if (path[path.size()-1] == '/') {
                path = path.substr(0, path.size()-1);
            }
            stack<string> res;
            int begin = 0, end = 0;
            while (path[end] == '/') end++;
            begin = end - 1;
            while (end < path.size()) {
                while (end < path.size() && path[end] != '/') end++;
                string temp = path.substr(begin, end-begin);
                std::cout << temp << std::endl;
                if (temp == "/.") {
                } else if (temp == "/..") {
                    if (!res.empty()) {
                        res.pop(); 
                    }
                } else {
                    res.push(temp);
                }
                while (end < path.size() && path[end] == '/') end++;
                begin = end - 1;
            }
            string simppath = "";
            while (!res.empty()) {
                simppath = res.top() + simppath;
                res.pop();
            }
            return simppath == "" ? "/" : simppath;
        }
};

int main() {
    Solution s;
    cout << s.simplifyPath("///TJbrd/owxdG//") << endl;
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
