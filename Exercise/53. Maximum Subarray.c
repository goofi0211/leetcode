int maxSubArray(int* nums, int numsSize){
    int i;
    if(numsSize==0)
        return 0;
    int r=nums[0],m=nums[0];
    for(i=1;i<numsSize;i++){
        if(r+nums[i]>nums[i])
            r=r+nums[i];
        else
            r=nums[i];
        m=fmax(m,r);
    }
    return m;
}