//big o(N)的作法 用兩個指標去左右逼近找出最大値 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int water=0;
        while(i<j){
            water=max(water,(j-i)*min(height[j],height[i]));
            if(height[j]>height[i])
                i++;
            else
                j--;
        }
        return water;
    }
};