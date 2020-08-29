//用一個長度為26的陣列
//紀錄每個字元第一次出現的位置，如果有字元之前已經重複出現 ，將他位置設在無窮大
int firstUniqChar(char * s){
    int position[26];
    memset(position,-1,26*sizeof(int));
    int i=0;
    while(*s!='\0'){
        if(position[*s-'a']==-1)//first time
            position[*s-'a']=i;
        else
            position[*s-'a']=2147483647;
        s++;
        i++;
    }
    int min=2147483647;
    for(int i=0;i<26;i++)
        if(position[i]>=0&&min>position[i]){
            min=position[i];
        }
    return min==2147483647?-1:min ;
}