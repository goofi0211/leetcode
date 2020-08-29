//最少要檢查最短字串數
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string ans="";
        int m=100000;
        for(int i=0;i<strs.size();i++){
            int len=strs[i].size();
            m = min(m,len);
        }
        char check;
        for(int k=0;k<m;k++){
            check=strs[0][k];
            for(int i=0;i<strs.size();i++){
                 if(strs[i][k]!=check)
                     return ans;
            }
            ans+=check;
        }
        return ans;
    }
};