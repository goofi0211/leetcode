/*遞迴
比如說a b c
     d e f 
     g h i
     對a 做遞迴 => a d做遞迴 =>a d g and so on...
     最後得到結果 
*/
vector<string>ans;
map<string,vector<string>>dic;
class Solution {
public:
    void dfs(string s,int index,string digits){
        if(index==digits.size()){
            ans.push_back(s);
            return ;
        }
        string id(1,digits[index]);
        for(int i=0;i<dic[id].size();i++){
            dfs(s+dic[id][i],index+1,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        ans.clear();
        if(digits.size()==0)return ans;
        dic["2"]={"a","b","c"};
        dic["3"]={"d","e","f"};
        dic["4"]={"g","h","i"};
        dic["5"]={"j","k","l"};
        dic["6"]={"m","n","o"};
        dic["7"]={"p","q","r","s"};
        dic["8"]={"t","u","v"};
        dic["9"]={"w","x","y","z"};
        dfs("",0,digits);
        return ans;
    }
    
};