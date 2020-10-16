/*假設想用k個硬幣組出amount
如果我已知k-1個硬幣可以組出amount
此時如果我有第k個硬幣，我就將之前k-1個硬幣可以組出amount-k的硬幣數+1就是我第k個硬幣組出amount的硬幣數
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int int_max=2147483646;
        vector<int>dp(amount+1,int_max);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j>=coins[i]){
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);
                }
            }
        }
        return dp[amount]==int_max?-1:dp[amount];
    }
};