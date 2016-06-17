/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file bst-iterator.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/03 13:20:19
 * @brief 
 *  
 **/
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 };

// next small number, 所以是先进先出，所以队列是最好的选择；
class BSTIterator {
    private:
        queue<int> myqueue;
    public:
        BSTIterator(TreeNode *root) {
            build_value(root);
        }

        void build_value(TreeNode *root) {
            if (NULL != root) {
                build_value(root->left);
                myqueue.push(root->val);
                build_value(root->right);
            }
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !myqueue.empty();

        }

        /** @return the next smallest number */
        int next() {
            int value = myqueue.front();
            myqueue.pop();
            return value;
        }
};

int main() {
    TreeNode v1(1);
    BSTIterator bst(NULL);
    printf("%d\n", bst.next());
}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
