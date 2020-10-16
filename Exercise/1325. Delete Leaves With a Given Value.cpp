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
// line 19 is very imprtant because we need to check the root after update will be the leave
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->val==target && root->left==root->right)return nullptr;
        if(root->left)root->left=removeLeafNodes(root->left,target);
        if(root->right)root->right=removeLeafNodes(root->right,target);
        if(root->val==target && root->left==root->right)return nullptr;
        return root;
    }
    
};