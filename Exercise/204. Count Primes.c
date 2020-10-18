//check the number is prime or not 
//only need to check 2~sqart(n)
int isprime(int);
int countPrimes(int n){
    int cnt=0;
    for(int i=2;i<n;i++){
        if(isprime(i))
            cnt++;
    }
    return cnt;
}
int isprime(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0)
            return 0;
    }
    return 1;
}