/*每一個element have two choice 
take or not take
so recursive ...
*/
class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0,"");
        return ans;
    }
    void dfs(vector<int>&nums,int index , string res){
        if(index==nums.size()){
            vector<int>temp;
            int f=0;
            for(int i=0;i<res.size();i++){
                temp.push_back(res[i]-'0');
            }
            ans.push_back(temp);
            return ;
        }
        char c=nums[index]+'0';//其實這邊有點問題如果他是負的，他會轉成奇怪的符號
        dfs(nums,index+1,res+c);//取
        dfs(nums,index+1,res);//不取
    }
};