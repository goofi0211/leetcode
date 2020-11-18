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
//recursive to the leave and check the path sum if we need
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>ans;
        vector<int>psum;
        mydfs(root,sum,psum,0,ans);
        return ans;
    }
    void mydfs(TreeNode* root, int sum,vector<int>psum,int mysum,vector<vector<int>>&ans){
        if(!root)return; 
        psum.push_back(root->val);
        mysum+=root->val;
        if(root->left==root->right && mysum==sum)
            ans.push_back(psum);
        else{
            if(root->left)mydfs(root->left,sum,psum,mysum,ans);
            if(root->right)mydfs(root->right,sum,psum,mysum,ans);
        }  
    }
};