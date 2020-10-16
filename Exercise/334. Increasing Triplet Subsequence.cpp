//n^2 approach can pass the testcase 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(findleft(i,nums)&&findright(i,nums))
                return true;
        }
        return false;
    }
    bool findleft(int i,vector<int>&nums){
        int n=nums[i];
        while(i>=0){
            if(nums[i]<n)
                return true;
            i--;
        }
        return false;
    }
    bool findright(int i,vector<int>&nums){
        int n=nums[i];
        while(i<nums.size()){
            if(nums[i]>n)
                return true;
            i++;
        }
        return false;
    }
};

//o(n) approach better than above
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int s1=INT_MAX,s2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(s1>nums[i]){
                s1=nums[i];
            }
            else if(s2>nums[i]&&nums[i]>s1)
                s2=nums[i];
            else if(nums[i]>s2)
                return true;
        }
        return false;
    }
};