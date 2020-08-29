//利用binarysort降低複雜度 從 n^2 => nlogn
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>>startpoints;
        vector<int>endpoints;
        vector<int>ans;
        int maxs=0;
        for(int i=0;i<intervals.size();i++){
            startpoints.push_back({intervals[i][0],i});
            endpoints.push_back(intervals[i][1]);
        }
        sort(startpoints.begin(),startpoints.end());
        int len=endpoints.size()-1;
        for(int i=0;i<endpoints.size();i++){
            bool f = false;
            int l=0,r=len;
            int temp=-1;
            while(l<=r){
                int m=(l+r)/2;
                if(startpoints[m].first>endpoints[i]){
                    r=m-1;
                    temp=startpoints[m].second;
                }
                else if(startpoints[m].first<endpoints[i])
                    l=m+1;
                else{
                    ans.push_back(startpoints[m].second);
                    f=true;;
                    break;
                }
            }
            if(!f){
                ans.push_back(temp);
            }
            
        }
        return ans;
    }
};