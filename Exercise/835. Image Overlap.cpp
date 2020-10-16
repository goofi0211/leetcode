class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,count(A,B,i,j,n));
            }
        }
        return ans;
    }
    int count(vector<vector<int>>& A, vector<vector<int>>& B,int shiftr,int shiftd,int n){
        int sum=0;
        for(int i=0;i<n-shiftd;i++){
            for(int j=0;j<n-shiftr;j++){
                sum+=A[i][j]*B[i+shiftd][j+shiftr];
            }
        }
        return sum;
    }
};