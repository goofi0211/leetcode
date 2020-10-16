class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //slide window approach 
        //make sure in interval i and j there is not element repeat
        int i=0,j=0,ans=0;
        set<char>dic;
        while(j<s.size()){
            if(dic.count(s[j]))//find repeat
                dic.erase(s[i++]);
            else{
                dic.insert(s[j]);
                ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};