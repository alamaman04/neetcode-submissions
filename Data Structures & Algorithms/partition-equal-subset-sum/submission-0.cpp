class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sm = accumulate(nums.begin() ,nums.end(),0) ;
        if(sm%2==1) return false ;
        sm/=2 ;

        vector<vector<int>>dp(n+1,vector<int>(sm + 1 ,false)) ;
        for(int i=0 ;i<=n;i++) dp[i][0] = true ;

        for(int i = 1 ;i <= n; i++){
            for(int j=1 ;j<= sm ;j++){
                dp[i][j]  = dp[i-1][j] ;
                
                if(nums[i-1]<=j) dp[i][j]|= dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sm] ;
    }
};
