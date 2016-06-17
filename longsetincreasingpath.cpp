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

// ���к�����һ���⣻
// ����DFS ��ÿ���㶼����һ���Ҵ�����������ľ��룬Ȼ��������е㣬�ᳬʱ��
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
                    // ÿ���㶼����Χ���ĸ��㣬�ʼ������ǳ�ʼ������ʲô��
                    // ��ʵ�ݹ��ȥ���������������ˣ�ÿ��������Χ����С�ĵ㣬��ô�ͻᵥ��ĵݹ飬һֱ������С���Ǹ���û���ݹ��ˣ�������1��
                    // Ȼ���𲽵ķ���ȥ�������ĵ㣬�����0��ʾ�Ѿ����ֱ�ӷ��أ������ظ����㣻
                    dp[x][y] = max(dp[x][y], dfs(matrix, nextx, nexty)+1); //��ʵҲ�Ǽ򵥵Ķ�̬�滮�� DFS��ÿ�����ʱ��������Χ�ĵ㣻
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
