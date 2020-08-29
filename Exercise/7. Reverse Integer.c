//這題比較特別的是要做overflow的判斷
//如果rev是我目前反轉的數，如果rev>int max/10那rev*10一定overflow，如果相等就要去看pop的值
//來決定會不會overflow
int int_M=2147483647;
int int_m=-2147483648;
int reverse(int x){
    int rev=0;
    if(x>0){
        while(x){
            int pop=x%10;
            if(rev>int_M/10)
                return 0;
            else if(rev==int_M&&pop>7)
                return 0;
            rev*=10;
            rev+=pop;
            x/=10;
        }
    }
    if(x<0){
        while(x){
            int pop=x%10;
            if(rev<int_m/10)
                return 0;
            else if(rev==int_m&&pop<-8)
                return 0;
            rev*=10;
            rev+=pop;
            x/=10;
        }
    }
    return rev;
}