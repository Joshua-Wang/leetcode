/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
/**
 * @file longsetincreasingpath.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/04 19:55:19
 * @brief 
 *  
 **/

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

// 很有含量的一道题；
// 单纯DFS ：每个点都搜了一遍找从这个点出发最长的距离，然后遍历所有点，会超时；
//
// DFS+DP 
// use a two dimensional matrix dp[i][j] to store the length of the longest increasing path starting
// at matrix[i][j]
//
// transferring function is: dp[i][j] = max(dp[i][j], dp[x][y] + 1), where dp[x][y] is its neighbor
// with matrix[x][y] < matrix[i][j]

class Solution {
    private : 
        int dp[1000][1000];

    public:
        int longestIncreasingPath(vector<vector<int> >& matrix) {
            if (matrix.size () == 0 || matrix[0].size() == 0) {
                return 0;
            }   
            int row = matrix.size();
            int col = matrix[0].size(); 
            memset(dp, 0, sizeof(int)*1000*1000);
            int res = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    res = max(res, dfs(matrix, i, j));
                }   
            }   
            return res;

        }   

        int dfs(vector<vector<int> >& matrix, int x, int y) {
            if (dp[x][y] != 0) {
                return dp[x][y];
            }   
            dp[x][y] = 1;
            int row = matrix.size();
            int col = matrix[0].size();
            int dir[][4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
            for (int i = 0; i < 4; i++) {
                int nextx = x+dir[i][0];
                int nexty = y+dir[i][1];
                if (nextx >= 0 && nextx < row && nexty >= 0 && nexty < col 
                        && matrix[nextx][nexty] < matrix[x][y]) {
                    // 每个点都用周围的四个点，最开始纠结的是初始条件是什么？
                    // 其实递归的去考虑这个问题就行了，每个点用周围比他小的点，那么就会单向的递归，一直先算最小的那个点没法递归了，它就是1；
                    // 然后逐步的返回去算其他的点，如果非0表示已经算过直接返回，避免重复计算；
                    dp[x][y] = max(dp[x][y], dfs(matrix, nextx, nexty)+1); //其实也是简单的动态规划， DFS算每个点的时候用了周围的点；
                }   
            }   
            return dp[x][y];
        }   
};

int main() {
    vector<vector<int> > matrix;
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    vector<int> v2;
    v2.push_back(3);
    v2.push_back(2);
    v2.push_back(6);

    vector<int> v3;
    v3.push_back(2);
    v3.push_back(2);
    v3.push_back(1);

    vector<int> v4;
    v4.push_back(1);
    v4.push_back(2);

    vector<int> v5;
    v5.push_back(4);
    v5.push_back(3);

    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    Solution s;
    cout << s.longestIncreasingPath(matrix) << endl;
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
