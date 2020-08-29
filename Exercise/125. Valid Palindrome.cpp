//判斷palindrome的方法
//1.將字串reverse，判斷跟原先字串相不相等
//2.最前字元要等於最後一個字元...
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0)
            return true;
        string t="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i]))
                t+=tolower(s[i]);
        }
        string t1=t;
        reverse(t.begin(),t.end());
        if(t==t1)
            return true;
        return false;
    }
};