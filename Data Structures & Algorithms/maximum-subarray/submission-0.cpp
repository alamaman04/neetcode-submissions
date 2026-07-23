class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;
        int sm = 0 ;
        int ans = INT_MIN ;
        for(int i=0 ;i<n;i++){
            sm+= nums[i];
            ans = max(ans,sm) ;
            if(sm<0) sm = 0 ;
        }
        return ans ;
    }
};
