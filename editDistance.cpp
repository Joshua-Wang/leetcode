/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file editDistance.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/10 10:43:42
 * @brief 
 *  
 **/

#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            int row = word1.length() + 1;
            int col = word2.length() + 1;

            int f[row][col];
            // f[0][0] = 0; f[0][1] = 1; f[1][0] = 1;
            // 这样初始化是不行的；因为i , j 都是从1开始算的，所以f[0][j] f[i][0]
            // 都是没计算的，所以dp的结果肯定不对；

            // 必须把 f[i][0] f[0][j] 都初始化；
            for (int i = 0; i < row; i++) {
                f[i][0] = i;
            }
            for (int j = 0; j < col; j++) {
                f[0][j] = j;
            }
            for (int i = 1; i < row; i++) 
                for (int j = 1; j < col; j++){
                    if (word1[i-1] == word2[j-1])
                        f[i][j] = f[i-1][j-1];
                    else
                        f[i][j] = f[i-1][j-1] + 1;
                    f[i][j] = min(f[i][j], min(f[i-1][j]+1, f[i][j-1]+1));
                }

            return f[row-1][col-1];
        }
};

int main(){
    string str1 = "sbea";
    string str2 = "ea";
    Solution s;
    cout << s.minDistance(str1, str2) << endl;

}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
