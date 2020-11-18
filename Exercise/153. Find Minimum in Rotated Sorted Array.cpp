// for loop the array check the break point
class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])
                return nums[i];
        }
        //if rotate time = 0
        return nums[0];
    }
};