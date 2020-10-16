/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//bottom up
class Solution {
public:
    
    int maxDepth(TreeNode* root) {
        int dep=dfs(root);
        return dep;
    }
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        return max(l,r)+1; 
    }
};
//top down 
class Solution {
public:
    int height=0;
    void mydfs (struct TreeNode*root,int h){
        if(root){
            height=max(height,h);
            mydfs(root->left,h+1);
            mydfs(root->right,h+1);
        }
    }
    int maxDepth(struct TreeNode* root){
        mydfs(root,1);
        return height;
    }
};