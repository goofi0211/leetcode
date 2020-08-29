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
//learn how to write a compare function for sort function "static" is important
class Solution {
public:
    vector<tuple<int,int,int>>vt;
    static bool comp(const tuple<int,int,int> &a, const tuple<int,int,int> &b){
        if(get<0>(a) < get<0>(b))
            return true;
        else if(get<0>(a) == get<0>(b) && get<1>(a) > get<1>(b))
            return true;
        else if(get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b))
            return true;
        else
            return false;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        sort(vt.begin(),vt.end(),comp);
        vector<int>temp;
        vector<vector<int>>ans;
        temp.push_back(get<2>(vt[0]));
        for(int i=1;i<vt.size();i++){
            if(get<0>(vt[i])!=get<0>(vt[i-1])){
                ans.push_back(temp);
                temp.clear();
                temp.push_back(get<2>(vt[i]));
            }
            else{
                temp.push_back(get<2>(vt[i]));
            }
        }
        ans.push_back(temp);
        return ans;
    }
    
    void dfs(TreeNode * root ,int x,int y){
        if(!root)
            return;
        vt.push_back({x,y,root->val});
        dfs(root->left,x-1,y-1);
        dfs(root->right,x+1,y-1);
    }
};