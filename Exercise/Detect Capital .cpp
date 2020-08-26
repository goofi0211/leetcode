class Solution {
public:
    bool detectCapitalUse(string word) {
        bool fc,allc=false,nor=false,notc=false;
        for(int i=0;i<word.size();i++){
            if(i==0){
                if(word[i]-'a'<0)//captial
                    fc=true;
                else
                    fc=false;
            }
            else if(i==1){
                if(word[i]-'a'<0&&fc)//allcaptial
                    allc=true;
                else if(word[i]-'a'>=0&&fc)//only first character captial
                    nor=true;
                else if(word[i]-'a'>=0&&!fc)//no captial
                    notc=true;
                else
                    return false;
            }
            else{
                if(word[i]-'a'<0&&allc)
                    continue;
                else if(word[i]-'a'>=0&&nor)
                    continue;
                else if(word[i]-'a'>=0&&notc)
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
};