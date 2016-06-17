#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		vector<string> binaryTreePaths(TreeNode* root) {
			vector<string> res;
			string str = "";
			search(root, res, str);
			return res;
		}

		void search(TreeNode* root, vector<string>& res, string& str) {
			if (root == NULL) {
				return;
			}
			char temp[10024] = {0}; 
			if (str == "") {
					sprintf(temp, "%d", root->val);
			} else {
					sprintf(temp, "%s->%d", str.c_str(), root->val);
			}
			str = string(temp);

			if (root->left == NULL && root->right == NULL) {
				res.push_back(str);
				return ;
			}
			string str_bak = str;
			search(root->left, res, str);
			search(root->right, res, str_bak);
		}
};










