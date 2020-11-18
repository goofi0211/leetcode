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
    int pathSum(TreeNode* root, int sum) {
        int ans=0;
        unordered_map<int,int>cache;
        cache[0]++;//放入dummy zero this is very important ex 0,1 target = 1 if we don't have dummy zero it will only output 1 didn't calculate 0->1
        mydfs(root,sum,0,cache,ans);
        return ans;
    }
    void mydfs(TreeNode* root,int &target,int pathsum,unordered_map<int,int>&cache,int &ans){
        if(!root)return ;
        pathsum+=root->val;//紀錄當前path的sum
        if(cache.count(pathsum-target)&&cache[pathsum-target]>0){
            ans+=cache[pathsum-target];
        }
        cache[pathsum]++;
        if(root->left)mydfs(root->left,target,pathsum,cache,ans);
        if(root->right)mydfs(root->right,target,pathsum,cache,ans);
        cache[pathsum]--;//because of call by reference
    }
};