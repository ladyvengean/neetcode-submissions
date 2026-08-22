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
    bool f(TreeNode* root, TreeNode* target){
        if(root == NULL){
            return false;
        }
        if(root == target){
            return true;
        }
        return f(root->left, target) || f(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return root;
        }
        if(root == p || root == q){
            return root;
        }
        if(f(root->left,p) != f(root->left, q)){
            return root;
        }
        if(f(root->left,p) && f(root->left, q) == true){
            return lowestCommonAncestor(root->left, p,q);
        }
        return lowestCommonAncestor(root->right,p,q);
    }
};
