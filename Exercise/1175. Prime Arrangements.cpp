class Solution {
public:
    int numPrimeArrangements(int n) {
        //how many primes in 1~n
        int primenum=countprimes(n);
        long long t=1;
        for(int i=1;i<=primenum;i++){
            t*=i;
            t%=1000000007;
        }
        int notprime=n-primenum;
        for(int i=1;i<=notprime;i++){
            t*=i;
            t%=1000000007;
        }
        return t;
    }
    int countprimes(int n){//count the number of prime in 1 to n
        int cnt=0;
        for(int i=2;i<=n;i++){
            if(isprime(i))
                cnt++;
        }
        return cnt;
    }
    bool isprime(int n){//check the number is prime or not
        for(int i=2;i*i<=n;i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
};