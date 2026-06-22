class Solution {
public:
    vector<vector<int>>ans ;

    void backtrack(int i ,vector<int>&sub, vector<int>&nums){
        if(i==nums.size()) {
            ans.push_back(sub) ; return ;
        }
        sub.push_back(nums[i]) ;
        backtrack(i+1,sub,nums) ;
        sub.pop_back() ;
        backtrack(i+1,sub,nums) ;
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>sub;
        backtrack(0,sub,nums) ;
        return ans ;
    }
};
