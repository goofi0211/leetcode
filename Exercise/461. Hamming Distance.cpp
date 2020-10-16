//bit operator
class Solution {
public:
    int hammingDistance(int x, int y) {
        int cntx=0,cnty=0;
        int t=0;
        int m=max(x,y);
        while(m>0){
            if((x&1)!=(y&1))
                t++;
            x>>=1;
            y>>=1;
            m>>=1;
        }
        return t;
    }
};