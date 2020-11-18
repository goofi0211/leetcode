//dynamic programing
//for each situation robber need to make dicision robbe or not 
//robbe i house profit=dp[i-2]+nums[i]
//not robbe i house profit = dp[i-1]

// it can't use greedy the greedy approach may be sum odd item and sum even item
// when the input become [3 1 1 4 ] the greedy method will be broken 
int rob(int* nums, int numsSize){
    int i;
    if(numsSize==0)
        return 0;
    else if(numsSize==1)
        return nums[0];
    int *dp=malloc(numsSize*sizeof(int));
    dp[0]=nums[0];
    dp[1]=fmax(nums[0],nums[1]);
    for(i=2;i<numsSize;i++){
        dp[i]=fmax(nums[i]+dp[i-2],dp[i-1]);
    }
    return dp[numsSize-1];
}