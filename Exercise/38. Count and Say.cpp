//這題寫過好多次了
//重點在於如果一個次串都是一樣的你的j會超出邊界
//這時如何去修正邊界問題
class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        n--;
        while(n--){
            string temp="";
            int j;
            for(int i=0;i<s.size();i=j){
                for(j=i;j<s.size();j++){
                    if(s[i]==s[j])
                        continue;
                    else{
                        temp+=(j-i)+'0';
                        temp+=s[i];
                        break;
                    }
                }
                if(j>=s.size()&&s[j-1]==s[i]){
                    temp+=(j-i)+'0';
                    temp+=s[i];
                }
            }
            s=temp;
        }
        return s;
    }
};