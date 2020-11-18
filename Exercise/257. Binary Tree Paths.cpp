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
//easy recursive
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
        sol(root,"",paths);
        return paths;
    }
    void sol(TreeNode* root,string path ,vector<string>&paths){
        if(!root)return ;
        if(root->left==root->right){
            path+=to_string(root->val);
            paths.push_back(path);
            return ;
        }
        path+=to_string(root->val)+"->";
        if(root->left)sol(root->left,path,paths);
        if(root->right)sol(root->right,path,paths);
    }
};