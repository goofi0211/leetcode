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
//subtree tell me the max length of the path
class Solution {
public:
    int longPath=0;
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return longPath;
        mydfs(root);
        return longPath-1;
    }
    int mydfs(TreeNode* root){
        if(!root)return 0;
        int len=1;
        int tmax=0;
        int left=0;
        int right=0;
        left=mydfs(root->left);
        right=mydfs(root->right);
        if(root->left&&root->left->val==root->val){ //--->check the child val equal to the parent or not 
            len+=left;
            tmax=max(tmax,left);
        }
        if(root->right&&root->right->val==root->val){//--->check the child val equal to the parent or not 
            len+=right;
            tmax=max(tmax,right);
        }
        longPath=max(len,longPath);
        return tmax+1;//--------------------->this return the max path subtree
    }
};