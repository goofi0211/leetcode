//取log在pow回去，如果一個是power of three 則他log 在power回去回和原來的值相等
bool isPowerOfThree(int n){
    if(n<=0)return false;
    int a =log10(n)/log10(3);
    if(pow(3,a)<n)
        return false;
    return true;
}