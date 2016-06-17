/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file maximal-square.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/19 20:41:32
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

class Solution {
    public:
        // 有了largestRectangleArea 的积累，这题太简单了；
        int maximalRectangle(vector<vector<char> >& matrix) {
            int row = matrix.size();
            if (row == 0) {
                return 0;
            }
            int col = matrix[0].size();
            if (col == 0) {
                return 0;      
            }
            vector<vector<int> > res;
            int maxValue = 0;
            for (int i = 0; i < row; i++) {
                vector<int> line;
                for (int j = 0; j < col; j++) {
                    if (matrix[i][j] == '0'){
                        line.push_back(0);
                    } else {
                        line.push_back(i > 0 ? res[i-1][j] + 1 : 1);
                    }
                }
                maxValue = max(maxValue, largestRectangleArea(line));
                res.push_back(line);
            }
            return maxValue;
    
        }

        int largestRectangleArea(vector<int>& heights) {
            stack<int> ss;
            heights.push_back(0);
            int res = 0;
            int i = 0;
            while (i < heights.size()) {
                if (ss.empty() || heights[ss.top()] <= heights[i]) {
                    ss.push(i);
                    i++;
                } else {
                    int tmp = ss.top();
                    ss.pop();
                    res = max(res, heights[tmp] * (ss.empty() ? i : i - ss.top() - 1));
                }
            }
            return res; 
            
        }

        // dp[i][j] 代表以i,j为右下角定点的正方形的最大边长；
        int maximalSquare(vector<vector<char> >& matrix) {
            int row = matrix.size();
            if (row == 0) { return 0; }
            int col = matrix[0].size();
            int dp[row][col];
            for (int i = 0; i < row; i++) {
                dp[i][0] = ( matrix[i][0] == '0' ? 0 : 1) ;
            }

            for (int i = 0; i < col; i++) {
                dp[0][i] = ( matrix[0][i] == '0' ? 0 : 1) ;
            }

            for (int i = 1; i < row; i++) {
                for (int j = 1; j < col; j++) {
                    if (matrix[i][j] == '0') {
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                }
            }
            int res = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    res = max(res, dp[i][j]);
                }
            }

            return res * res;

        }

};

int main() 
{
    
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
