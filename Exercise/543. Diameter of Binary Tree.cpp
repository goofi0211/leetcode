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
//bottom up approach 
//the max diameter must be the long left road + the long right road+1 
//check every node from leaf to root
class Solution {
public:
    int max_diameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return max_diameter;
        mydfs(root);
        return max_diameter-1;    
    }
    int mydfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int left=mydfs(root->left);
        int right=mydfs(root->right);
        max_diameter=max(max_diameter,left+right+1);
        return max(left,right)+1;
    }
};