/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file word-search.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/01 22:57:50
 * @brief 
 *  
 **/

#include <vector>
#include <string>

using namespace std;
//
// gcc -g 产生的a.out 才可以gdb 
// 过的比较痛苦；
// gdb 才是神器，有问题的都要调试；
class Solution {
    public:
        int visited[1000][1000];

        bool exist(vector<vector<char> >& board, string word) {
            if (board.size() == 0) {
                return false;
            }
            if (word.size() == 0) {
                return true;
            }
            int row = board.size();
            int col = board[0].size();
            memset(visited, 0, sizeof(visited));
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (word[0] == board[i][j]) {
                        visited[i][j] = 1;
                        if (search(i, j, 1, word, board)) {
                            return true;
                        }
                        visited[i][j] = 0;
                    }
                }
            }
            return false;
        }

        bool search(int row, int col, int index, string word, vector<vector<char> >& board) {
            if (index == word.size()) {
                return true;
            }
            int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
            for (int i = 0; i < 4; i++) {
                int next_row = row+dir[i][0];
                int next_col = col+dir[i][1];
                if (next_row < 0 || next_row >= board.size() || next_col < 0 || next_col >= board[0].size()) {
                    continue;
                }
                if (!visited[next_row][next_col] && word[index] == board[next_row][next_col]) {
                    visited[next_row][next_col] = 1;
                    if (search(next_row, next_col, index+1, word, board)) { // 开始这里用的index++，结果回溯的时候index值自增了；所以一直报错。。。
                        return true;
                    }
                    visited[next_row][next_col] = 0;
                } 
            }
            return false;
        }
};

int main() {
    vector<char> v1;
    v1.push_back('A');
    v1.push_back('B');

    vector<char> v2;
    v2.push_back('C');
    v2.push_back('D');

    vector<char> v3;
    v3.push_back('A');
    v3.push_back('D');
    v3.push_back('E');
    v3.push_back('E');
    
    vector<vector<char> > board;
    board.push_back(v1);
    board.push_back(v2);

    Solution s;
    if (s.exist(board, "ABCD")) {
        printf("yes\n");
    }
    return 0;
}















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
