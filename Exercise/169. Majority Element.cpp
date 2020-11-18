// use a map to count the times of each number and check the time if more than half
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>dic;
        int m=-1;
        for(int i :nums){
            dic[i]++;
            m=max(m,dic[i]);
            if(m>nums.size()/2)
                return i;
        }
        return 0;
    }
};