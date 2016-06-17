/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file balanced_tree.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/03 14:13:04
 * @brief 
 *  
 **/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            if (NULL == root) {
                return true;
            }
            if (!isBalanced(root->left) || !isBalanced(root->right)) {
                return false;
            }
            int lh = getHeight(root->left);
            int rh = getHeight(root->right);
            if (lh - rh >= -1 && lh - rh <= 1) {
                return true;
            } else {
                return false;
            }

        }

        int getHeight(TreeNode* root) {
            if (NULL == root) {
                return 0;
            }
            int lh = getHeight(root->left);
            int rh = getHeight(root->right);
            return max(lh, rh) + 1;
        }
};



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
