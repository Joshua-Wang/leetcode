/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
/**
 * @file invert-binary-tree.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/03/27 10:59:19
 * @brief 
 *  
 **/
#include <stdio.h>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if (NULL == root) {
                return NULL;
            }
            TreeNode* temp;
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }

        TreeNode* invertTreeNoneReverse(TreeNode* root) {
            stack<TreeNode* > mystack;
            if (NULL == root) {
                return NULL;
            } else {
                mystack.push(root);
            }
            while (!mystack.empty()) {
                TreeNode* head = mystack.top();
                mystack.pop();
                TreeNode* temp;
                temp = head->left;
                head->left = head->right;
                head->right = temp;
                if (head->left) {
                    mystack.push(head->left);
                }
                if (head->right) {
                    mystack.push(head->right);
                }
            }
            return root;
        }

};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */











