/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//solution 1: time complexity o(n^2)
//not using the charastice of BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>p1,p2;
        dfs(root,p,p1);
        dfs(root,q,p2);
        for(int i=p1.size()-1;i>=0;i--){ //----------->this the bottle neck
            for(int j=p2.size()-1;j>=0;j--){
                if(p1[i]==p2[j])
                    return p1[i];
            }
        }
        return nullptr;
    }
    bool dfs(TreeNode* root, TreeNode* target,vector<TreeNode*>&path){
        if(!root)return false;
        path.push_back(root);
        if(root==target){
            return true;
        }
        if( dfs(root->left,target,path) )return true;
        if( dfs(root->right,target,path) )return true;
        path.pop_back(); //------------->call by reference when we recursive back we need to pop out
        return false;
    }
};
//solutiuon 2:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//using the charastic of BST the code be short and easier to read
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int M=max(p->val,q->val);
        int m=min(p->val,q->val);
        if(root->val>=m&&root->val<=M)
            return root;
        if(root->val>M) return lowestCommonAncestor(root->left,p,q);
        if(root->val<m) return lowestCommonAncestor(root->right,p,q);
        return nullptr;
    }
};