/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void f(TreeNode* node, int level, vector<int>& ls){
        if(node == NULL){
            return;
        }
        if(ls.size() == level){
            ls.push_back(node->val);
        }
        f(node->right, level+1, ls);
        f(node->left, level+1,ls);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ls;
        f(root,0,ls);
        return ls;
    }
};
