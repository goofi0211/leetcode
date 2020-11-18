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
//use dynamic approach d[i]=max(d[i-1],d[i-1]+rob)
//bottom up approach with store value in cache to spped up recursive
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>cache;
        return mydfs(root,cache);
    }
    int mydfs(TreeNode*root,unordered_map<TreeNode*,int>&cache){
        if(!root)return 0;
        if(cache.count(root))return cache[root];
        if(root->left==root->right)return root->val;
        int gleft=0,gright=0,left=0,right=0;
        if(root->left){
            left=mydfs(root->left,cache);
            gleft=mydfs(root->left->left,cache)+mydfs(root->left->right,cache);
        }
        if(root->right){
            right=mydfs(root->right,cache);
            gright=mydfs(root->right->left,cache)+mydfs(root->right->right,cache);
        }
        cache[root]=max(left+right,gleft+gright+root->val);
        return max(left+right,gleft+gright+root->val);
    }
};