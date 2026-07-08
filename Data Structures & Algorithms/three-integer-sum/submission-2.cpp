class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() ,nums.end());
        int n = nums.size();
        vector<vector<int>> ans ;

        map<vector<int> ,bool> mpp ;
        for(int i=0 ;i<n;i++){
            int l = i+1 , r = n-1 ;
            int target = nums[i] * -1 ;
            while(l<r){
                int sm = nums[l]+ nums[r] ;
                if(sm==target) {
                    vector<int> v = {nums[i],nums[l],nums[r]} ;
                    if(!mpp[v]) {
                        ans.push_back(v);
                        mpp[v] = true ;
                    }
                    l++;
                }else if(sm>target) r-- ;
                else l++ ;
            }
        }
        return ans ;
    }
};
