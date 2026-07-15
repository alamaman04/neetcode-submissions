class Solution {
public:
    // vector<vector<int>>memo ;
    // int rec(int idx , int sm ,int &target,int &total ,vector<int>&nums){
    //     if(idx==nums.size()){
    //         if(sm== target) return 1 ;
    //         return 0 ;
    //     }
    //     if(memo[idx][sm+total]!= -1) return memo[idx][sm+total] ;
    //     int ways = 0 ;
    //     ways += rec(idx+1,sm+nums[idx],target,total,nums) ;
    //     ways += rec(idx+1,sm-nums[idx],target,total,nums) ;

    //     return memo[idx][sm+total] = ways ;
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ;
        int total = accumulate(nums.begin(),nums.end(),0);

        // memo.assign(n+1,vector<int>(2*total+1,-1)) ;
        // if(target> total || target< -1*total) return 0 ;
        // return rec(0,0,target,total,nums) ;
        
        // bottom up 
        vector<unordered_map<int,int>>dp(n+1) ;
        dp[0][0] =1 ;

        for(int i=1 ;i<=n;i++){
            for(auto &p : dp[i-1]){
                dp[i][p.first+nums[i-1]] += p.second ;
                dp[i][p.first-nums[i-1]] += p.second ;
            }
        }
        return dp[n][target] ;
    }
};
