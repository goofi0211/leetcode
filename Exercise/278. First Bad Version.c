// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
//easy binary search 
//it is worth nothing that (l+r)/2 might overflow so turn it to l+(r-l)/2
int firstBadVersion(int n) {
    int l=1,r=n;
    while(l<=r){
        int m=l+(r-l)/2;
        if(isBadVersion(m)==true)
            r=m-1;
        else
            l=m+1;
    }
    return l;
}