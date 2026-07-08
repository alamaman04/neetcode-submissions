class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() ,nums.end());
        int n = nums.size();
        vector<vector<int>> ans ;

        map<vector<int> ,bool> mpp ;
        for(int i=0 ;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue ;
            int l = i+1 , r = n-1 ;
            int target = nums[i] * -1 ;
            while(l<r){
                int sm = nums[l]+ nums[r] ;
                if(sm==target) {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++ ;
                    while(l<r && nums[l]==nums[l-1]) l++ ;
                }else if(sm>target) r-- ;
                else l++ ;
            }
        }
        return ans ;
    }
};
