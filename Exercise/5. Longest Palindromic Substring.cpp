//learn from huahua complexity n^2
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0)return "";
        int ans=0,start;//ans record the final maximun length
        for(int i=0;i<s.size();i++){
            int cur;
            cur=max(getlen(i,i,s.size(),s),getlen(i,i+1,s.size(),s));
            if(ans<cur){
                ans=cur;
                start=i-(ans-1)/2;
            }
        }
        return s.substr(start,ans);
    }
    int getlen(int l,int r,int size,string&s){
        while(l>=0&&r<size&&s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
};